/******************************************************************************
 * Copyright (c) 2018-2024 openblack developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/openblack/openblack
 *
 * openblack is licensed under the GNU General Public License version 3.
 *******************************************************************************/

#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/intersect.hpp>
#include <glm/gtx/vec_swizzle.hpp>

#include "3D/LandIslandInterface.h"
#include "ECS/Registry.h"
#include "ECS/Systems/DynamicsSystemInterface.h"
#include "Input/GameActionMapInterface.h"
#include "Locator.h"
#include "ReflectionXZCamera.h"
#include "Windowing/WindowingInterface.h"

using namespace openblack;

namespace
{
constexpr auto k_DefaultCameraOriginOffset = glm::vec3(0.0f, 0.0f, 120.0f);
constexpr auto k_ReverseZMatrix = glm::mat4(1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, -1.f, 0.f, 0.f, 0.f, 1.f, 1.f);
} // namespace

Camera::Camera(glm::vec3 focus)
    // Maybe a struct is not the right thing... Maybe an optional?
    : _originInterpolators(ZoomInterpolator3f(focus + k_DefaultCameraOriginOffset))
    , _focusInterpolators(ZoomInterpolator3f(focus))
    , _model(CameraModel::CreateModel(CameraModel::Model::DefaultWorld))
{
}

Camera::~Camera() = default;

float Camera::GetHorizontalFieldOfView() const
{
	return _xFov;
}

glm::mat4 Camera::GetRotationMatrix() const
{
	return static_cast<glm::mat3>(glm::transpose(GetViewMatrix(Camera::Interpolation::Current)));
}

glm::mat4 Camera::GetViewMatrix(Interpolation interpolation) const
{
	// Invert the camera's rotation (transposed) and position (negated) to get the view matrix.
	return glm::lookAt(GetOrigin(interpolation), GetFocus(interpolation), glm::vec3(0.0f, 1.0f, 0.0f));
}

glm::mat4 Camera::GetViewProjectionMatrix(Interpolation interpolation) const
{
	return GetProjectionMatrix() * GetViewMatrix(interpolation);
}

glm::mat4 Camera::GetViewProjectionMatrix(Projection projection, Interpolation interpolation) const
{
	return GetProjectionMatrix(projection) * GetViewMatrix(interpolation);
}

std::optional<ecs::components::Transform> Camera::RaycastMouseToLand(bool includeWater, Interpolation interpolation) const
{
	// get the hit by raycasting to the land down via the mouse
	const auto mousePosition = Locator::gameActionSystem::value().GetMousePosition();
	const auto screenSize = Locator::windowing::value().GetSize();
	return RaycastScreenCoordToLand(static_cast<glm::vec2>(mousePosition) / static_cast<glm::vec2>(screenSize), includeWater,
	                                interpolation);
}

std::optional<ecs::components::Transform> Camera::RaycastScreenCoordToLand(glm::vec2 screenCoord, bool includeWater,
                                                                           Interpolation interpolation) const
{
	// get the hit by raycasting to the land down via the pixel coordinate
	ecs::components::Transform intersectionTransform;
	float intersectDistance = 0.0f;
	glm::vec3 rayOrigin;
	glm::vec3 rayDirection;
	DeprojectScreenToWorld(screenCoord, rayOrigin, rayDirection, interpolation);
	const auto& dynamicsSystem = Locator::dynamicsSystem::value();
	if (auto hit = dynamicsSystem.RayCastClosestHit(rayOrigin, rayDirection, 1e10f))
	{
		intersectionTransform = hit->first;
		return std::make_optional(intersectionTransform);
	}
	if (includeWater && glm::intersectRayPlane(rayOrigin, rayDirection, glm::vec3(0.0f, 0.0f, 0.0f),
	                                           glm::vec3(0.0f, 1.0f, 0.0f), intersectDistance))
	{
		intersectionTransform.position = rayOrigin + rayDirection * intersectDistance;
		intersectionTransform.rotation = glm::mat3(1.0f);
		return std::make_optional(intersectionTransform);
	}
	return std::nullopt;
}

Camera& Camera::SetProjectionMatrixPerspective(float xFov, float aspect, float nearClip, float farClip)
{
	_xFov = glm::radians(xFov);
	const float yFov = (glm::atan(glm::tan(_xFov / 2.0f) / aspect)) * 2.0f;
	// Inverse near and far for reverse z, we need to translate z by 1 to get back to the [0 1] range
	_projectionMatrix = glm::perspective(yFov, aspect, nearClip, farClip);
	_projectionMatrixReversedZ = k_ReverseZMatrix * _projectionMatrix;

	return *this;
}

Camera& Camera::SetInterpolatorTime(std::chrono::microseconds t)
{
	_interpolatorTime = t;

	return *this;
}

glm::vec3 Camera::GetForward() const
{
	// Forward is +1 in openblack but is -1 in OpenGL
	return static_cast<glm::mat3>(GetRotationMatrix()) * glm::vec3(0.0f, 0.0f, 1.0f);
}

glm::vec3 Camera::GetRight() const
{
	return static_cast<glm::mat3>(GetRotationMatrix()) * glm::vec3(1.0f, 0.0f, 0.0f);
}

glm::vec3 Camera::GetUp() const
{
	return static_cast<glm::mat3>(GetRotationMatrix()) * glm::vec3(0.0f, 1.0f, 0.0f);
}

std::unique_ptr<Camera> Camera::Reflect() const
{
	// TODO(bwrsandman): The copy to reflection camera has way too much of Camera including model which is useless
	//                   This also touches on other cameras such as the citadel camera which use a different kind of model
	auto reflectionCamera = std::make_unique<ReflectionXZCamera>();
	(*reflectionCamera).SetOrigin(GetOrigin()).SetFocus(GetFocus()).SetProjectionMatrix(_projectionMatrix);
	return reflectionCamera;
}

void Camera::DeprojectScreenToWorld(glm::vec2 screenCoord, glm::vec3& outWorldOrigin, glm::vec3& outWorldDirection,
                                    Interpolation interpolation) const
{
	const float screenSpaceX = (screenCoord.x - 0.5f) * 2.0f;
	const float screenSpaceY = ((1.0f - screenCoord.y) - 0.5f) * 2.0f;

	// The start of the ray trace is defined to be at mousex,mousey,1 in
	// projection space (z=1 is near, z=0 is far - this gives us better
	// precision) To get the direction of the ray trace we need to use any z
	// between the near and the far plane, so let's use (mousex, mousey, 0.5)
	const glm::vec4 rayStartProjectionSpace = glm::vec4(screenSpaceX, screenSpaceY, 0.0f, 1.0f);
	const glm::vec4 rayEndProjectionSpace = glm::vec4(screenSpaceX, screenSpaceY, 0.5f, 1.0f);

	// Calculate our inverse view projection matrix
	auto inverseViewProj = glm::inverse(GetViewProjectionMatrix(Projection::Normal, interpolation));

	// Get our homogeneous coordinates for our start and end ray positions
	const glm::vec4 hgRayStartWorldSpace = inverseViewProj * rayStartProjectionSpace;
	const glm::vec4 hgRayEndWorldSpace = inverseViewProj * rayEndProjectionSpace;

	glm::vec3 rayStartWorldSpace(hgRayStartWorldSpace.x, hgRayStartWorldSpace.y, hgRayStartWorldSpace.z);
	glm::vec3 rayEndWorldSpace(hgRayEndWorldSpace.x, hgRayEndWorldSpace.y, hgRayEndWorldSpace.z);

	// divide vectors by W to undo any projection and get the 3-space coord
	if (hgRayStartWorldSpace.w != 0.0f)
	{
		rayStartWorldSpace /= hgRayStartWorldSpace.w;
	}

	if (hgRayEndWorldSpace.w != 0.0f)
	{
		rayEndWorldSpace /= hgRayEndWorldSpace.w;
	}

	const glm::vec3 rayDirWorldSpace = glm::normalize(rayEndWorldSpace - rayStartWorldSpace);

	// finally, store the results in the outputs
	outWorldOrigin = rayStartWorldSpace;
	outWorldDirection = rayDirWorldSpace;
}

bool Camera::ProjectWorldToScreen(glm::vec3 worldPosition, glm::vec4 viewport, glm::vec3& outScreenPosition,
                                  Interpolation interpolation) const
{
	if (glm::all(glm::epsilonEqual(worldPosition, GetOrigin(), glm::epsilon<float>())))
	{
		outScreenPosition = glm::vec3(glm::lerp(glm::xy(viewport), glm::zw(viewport), {0.5f, 0.5f}), 0.0f);
		return true; // Right at the camera position
	}
	outScreenPosition =
	    glm::project(worldPosition, GetViewMatrix(interpolation), GetProjectionMatrix(Projection::Normal), viewport);
	if (outScreenPosition.x < viewport.x || outScreenPosition.y < viewport.y || glm::round(outScreenPosition.x) > viewport.z ||
	    glm::round(outScreenPosition.y) > viewport.w)
	{
		return false; // Outside viewport bounds
	}
	if (outScreenPosition.z > 1.0f)
	{
		return false; // Clipped
	}
	if (outScreenPosition.z < 0.0f)
	{
		return false; // Behind Camera
	}
	outScreenPosition.y = viewport.w - (outScreenPosition.y - viewport.y) + viewport.y;
	return true;
}

void Camera::Update(std::chrono::microseconds dt)
{
	using namespace std::chrono_literals;

	const auto updateInfo = _model->Update(dt, *this);

	if (updateInfo)
	{
		const auto m1 = glm::zero<glm::vec3>();
		// You have to normalize the velocity with the NEW duration
		const auto durationSeconds = std::chrono::duration_cast<std::chrono::duration<float>>(updateInfo->duration);
		SetOriginInterpolator(GetOrigin(), updateInfo->origin, GetOriginVelocity() * durationSeconds.count(), m1);
		SetFocusInterpolator(GetFocus(), updateInfo->focus, GetFocusVelocity() * durationSeconds.count(), m1);
		SetInterpolatorDuration(updateInfo->duration);
		SetInterpolatorTime(0us);
	}

	const auto duration = GetInterpolatorDuration().count();
	if (duration == 0.0f)
	{
		SetInterpolatorT(1.0f);
	}
	else
	{
		AddInterpolatorTime(std::min(100'000us, dt));
	}
}

void Camera::HandleActions(std::chrono::microseconds dt)
{
	_model->HandleActions(dt);
}

const glm::mat4& Camera::GetProjectionMatrix() const
{
	return GetProjectionMatrix(_cameraProjection);
}

const glm::mat4& Camera::GetProjectionMatrix(Projection projection) const
{
	switch (projection)
	{
	case Projection::Normal:
		return _projectionMatrix;
	case Projection::ReversedZ:
		return _projectionMatrixReversedZ;
	default:
		assert(false);
		std::unreachable();
	}
}

glm::vec3 Camera::GetOrigin(Interpolation interpolation) const
{
	switch (interpolation)
	{
	case Interpolation::Current:
		return _originInterpolators.PositionAt(GetInterpolatorT());
	case Interpolation::Start:
		return _originInterpolators.p0;
	case Interpolation::Target:
		return _originInterpolators.p1;
	default:
		assert(false);
		std::unreachable();
	}
}

glm::vec3 Camera::GetFocus(Interpolation interpolation) const
{
	switch (interpolation)
	{
	case Interpolation::Current:
		return _focusInterpolators.PositionAt(GetInterpolatorT());
	case Interpolation::Start:
		return _focusInterpolators.p0;
	case Interpolation::Target:
		return _focusInterpolators.p1;
	default:
		assert(false);
		std::unreachable();
	}
}

glm::vec3 Camera::GetOriginVelocity(Interpolation interpolation) const
{
	glm::vec3 result;
	switch (interpolation)
	{
	case Interpolation::Current:
		result = _originInterpolators.VelocityAt(GetInterpolatorT());
		break;
	case Interpolation::Start:
		result = _originInterpolators.v0;
		break;
	case Interpolation::Target:
		result = _originInterpolators.v1;
		break;
	default:
		assert(false);
		std::unreachable();
	}

	if (_interpolatorDuration == decltype(_interpolatorDuration)::zero())
	{
		return result;
	}
	return result / std::chrono::duration_cast<std::chrono::duration<float>>(_interpolatorDuration).count();
}

glm::vec3 Camera::GetFocusVelocity(Interpolation interpolation) const
{
	glm::vec3 result;
	switch (interpolation)
	{
	case Interpolation::Current:
		result = _focusInterpolators.VelocityAt(GetInterpolatorT());
		break;
	case Interpolation::Start:
		result = _focusInterpolators.v0;
		break;
	case Interpolation::Target:
		result = _focusInterpolators.v1;
		break;
	default:
		assert(false);
		std::unreachable();
	}

	if (_interpolatorDuration == decltype(_interpolatorDuration)::zero())
	{
		return result;
	}
	return result / std::chrono::duration_cast<std::chrono::duration<float>>(_interpolatorDuration).count();
}

glm::vec3 Camera::GetRotation() const
{
	// Extract the yaw, pitch, and roll angles from the rotation matrix
	float yaw;
	float pitch;
	float roll;

	// Use the GLM function `extractEulerAngleYXZ` to get the Euler angles
	glm::extractEulerAngleZYX(GetRotationMatrix(), roll, yaw, pitch);
	// Fix angles to make sure roll is 0, it tends to flip to 180 and -180
	if (roll > glm::radians(90.0f) || roll < glm::radians(-90.0f))
	{
		pitch -= glm::radians(180.0f) * glm::sign(pitch);
		yaw = glm::radians(180.0f) - yaw;
	}
	return {pitch, yaw, 0.0f};
}

Camera& Camera::SetOrigin(const glm::vec3& position)
{
	_originInterpolators = ZoomInterpolator3f(position);

	return *this;
}

Camera& Camera::SetFocus(const glm::vec3& position)
{
	_focusInterpolators = ZoomInterpolator3f(position);

	return *this;
}

Camera& Camera::SetOriginInterpolator(const glm::vec3& p0, const glm::vec3& p1, const glm::vec3& m0, const glm::vec3& m1)
{
	_originInterpolators = ZoomInterpolator3f(p0, p1, m0, m1);

	return *this;
}

Camera& Camera::SetFocusInterpolator(const glm::vec3& p0, const glm::vec3& p1, const glm::vec3& m0, const glm::vec3& m1)
{
	_focusInterpolators = ZoomInterpolator3f(p0, p1, m0, m1);

	return *this;
}

Camera& Camera::SetInterpolatorDuration(std::chrono::microseconds duration)
{
	_interpolatorDuration = duration;

	return *this;
}

Camera& Camera::SetProjectionMatrix(const glm::mat4& projection)
{
	_projectionMatrix = projection;
	_projectionMatrixReversedZ = k_ReverseZMatrix * _projectionMatrix;

	return *this;
}
Camera::Projection Camera::GetCameraProjection() const
{
	return _cameraProjection;
}
