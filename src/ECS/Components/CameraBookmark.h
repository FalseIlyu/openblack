/*******************************************************************************
 * Copyright (c) 2018-2024 openblack developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/openblack/openblack
 *
 * openblack is licensed under the GNU General Public License version 3.
 *******************************************************************************/

#pragma once

#include <cstdint>

#include <chrono>

#include <glm/vec3.hpp>

namespace openblack::ecs::components
{
struct CameraBookmark
{
	uint8_t number;
	float animationTime;
	glm::vec3 savedOrigin;
};

} // namespace openblack::ecs::components
