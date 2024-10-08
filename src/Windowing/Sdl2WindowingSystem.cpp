/******************************************************************************
 * Copyright (c) 2018-2024 openblack developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/openblack/openblack
 *
 * openblack is licensed under the GNU General Public License version 3.
 *******************************************************************************/

#define LOCATOR_IMPLEMENTATIONS

#include "Sdl2WindowingSystem.h"

#include <SDL_syswm.h>
#include <spdlog/spdlog.h>

#if defined(SDL_VIDEO_DRIVER_WAYLAND)
#include <wayland-egl.h>
#endif // defined(SDL_VIDEO_DRIVER_WAYLAND)
#if defined(SDL_VIDEO_DRIVER_COCOA)
void* cbSetupMetalLayer(void* wnd);
#endif

#include <SDL.h>

using namespace openblack::windowing;

void Sdl2WindowingSystem::SDLDestroyer::operator()(SDL_Window* window) const
{
	SDL_DestroyWindow(window);
}

Sdl2WindowingSystem::Sdl2WindowingSystem(const std::string& title, int width, int height, DisplayMode displayMode,
                                         uint32_t extraFlags)
{
	SDL_version compiledVersion;
	SDL_VERSION(&compiledVersion);

	SDL_version linkedVersion;
	SDL_GetVersion(&linkedVersion);

	SPDLOG_LOGGER_INFO(spdlog::get("graphics"), "Initializing SDL...");
	SPDLOG_LOGGER_INFO(spdlog::get("graphics"), "SDL Version/Compiled {}.{}.{}", //
	                   compiledVersion.major, compiledVersion.minor, compiledVersion.patch);
	SPDLOG_LOGGER_INFO(spdlog::get("graphics"), "SDL Version/Linked {}.{}.{}", //
	                   linkedVersion.major, linkedVersion.minor, linkedVersion.patch);

	// Initialize SDL
	if (SDL_WasInit(0) == 0)
	{
		SDL_SetMainReady();
		if (SDL_Init(0) != 0)
		{
			throw std::runtime_error("Could not initialize SDL: " + std::string(SDL_GetError()));
		}

		if (SDL_InitSubSystem(SDL_INIT_VIDEO) != 0)
		{
			throw std::runtime_error("Could not initialize SDL Video Subsystem: " + std::string(SDL_GetError()));
		}

		if (SDL_InitSubSystem(SDL_INIT_TIMER) != 0)
		{
			throw std::runtime_error("Could not initialize SDL Timer Subsystem: " + std::string(SDL_GetError()));
		}
	}

	SDL_ShowCursor(SDL_DISABLE);
	SDL_SetHint(SDL_HINT_VIDEO_EXTERNAL_CONTEXT, "1");

	uint32_t flags = SDL_WINDOW_INPUT_FOCUS | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI | extraFlags;
	if (displayMode == DisplayMode::Fullscreen)
	{
		flags |= SDL_WINDOW_FULLSCREEN;
	}
	else if (displayMode == DisplayMode::Borderless)
	{
		flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
	}

	// Get SDL Window requirements from Renderer
	const int x = SDL_WINDOWPOS_UNDEFINED;
	const int y = SDL_WINDOWPOS_UNDEFINED;

	auto window = std::unique_ptr<SDL_Window, SDLDestroyer>(SDL_CreateWindow(title.c_str(), x, y, width, height, flags));

	if (window == nullptr)
	{
		SPDLOG_LOGGER_ERROR(spdlog::get("graphics"), "Failed to create SDL2 window: '{}'", SDL_GetError());
		throw std::runtime_error("Failed creating SDL2 window: " + std::string(SDL_GetError()));
	}

	_window = std::move(window);
}

void* Sdl2WindowingSystem::GetHandle() const
{
	return _window.get();
}

Sdl2WindowingSystem::NativeHandles Sdl2WindowingSystem::GetNativeHandles() const
{
	NativeHandles result {nullptr, nullptr};
#if defined(__EMSCRIPTEN__)
	static const char* canvas = "#canvas";
	nativeWindow = const_cast<void*>(reinterpret_cast<const void*>(canvas));
	return;
#endif

	SDL_SysWMinfo wmi;
	SDL_VERSION(&wmi.version);
	if (SDL_GetWindowWMInfo(_window.get(), &wmi) == 0u)
	{
		throw std::runtime_error("Failed getting native window info: " + std::string(SDL_GetError()));
	}

	// clang-format off
	// Linux
#if defined(SDL_VIDEO_DRIVER_WAYLAND)
	if (wmi.subsystem == SDL_SYSWM_WAYLAND)
	{
		auto* winImpl = static_cast<wl_egl_window*>(SDL_GetWindowData(_window.get(), "wl_egl_window"));
		if (winImpl == nullptr)
		{
			int width;
			int height;
			SDL_GetWindowSize(_window.get(), &width, &height);
			struct wl_surface* surface = wmi.info.wl.surface;
			if (surface == nullptr)
			{
				throw std::runtime_error("Failed getting native window handles: " + std::string(SDL_GetError()));
			}
			winImpl = wl_egl_window_create(surface, width, height);
			SDL_SetWindowData(_window.get(), "wl_egl_window", winImpl);
		}
		// NOLINTNEXTLINE(performance-no-int-to-ptr)
		result.nativeWindow = reinterpret_cast<void*>(winImpl);
		result.nativeDisplay = wmi.info.wl.display;
	}
	else
#endif // defined(SDL_VIDEO_DRIVER_WAYLAND)
#if defined(SDL_VIDEO_DRIVER_X11)
	if (wmi.subsystem == SDL_SYSWM_X11)
	{
		// NOLINTNEXTLINE(performance-no-int-to-ptr)
		result.nativeWindow = reinterpret_cast<void*>(wmi.info.x11.window);
		result.nativeDisplay = wmi.info.x11.display;
	}
	else
#endif // defined(SDL_VIDEO_DRIVER_X11)

	// Mac
#if defined(SDL_VIDEO_DRIVER_COCOA)
	if (wmi.subsystem == SDL_SYSWM_COCOA)
	{
		result.nativeWindow = cbSetupMetalLayer(wmi.info.cocoa.window);
		result.nativeDisplay = nullptr;
	}
	else
#endif // defined(SDL_VIDEO_DRIVER_COCOA)

	// Windows
#if defined(SDL_VIDEO_DRIVER_WINDOWS)
	if (wmi.subsystem == SDL_SYSWM_WINDOWS)
	{
		result.nativeWindow = wmi.info.win.window;
		result.nativeDisplay = nullptr;
	}
	else
#endif // defined(SDL_VIDEO_DRIVER_WINDOWS)

	// Steam Link
#if defined(SDL_VIDEO_DRIVER_VIVANTE)
	if (wmi.subsystem == SDL_SYSWM_VIVANTE)
	{
		result.nativeWindow = wmi.info.vivante.window;
		result.nativeDisplay = wmi.info.vivante.display;
	}
	else
#endif // defined(SDL_VIDEO_DRIVER_VIVANTE)

	// Android
#if defined(SDL_VIDEO_DRIVER_ANDROID)
	if (wmi.subsystem == SDL_SYSWM_ANDROID)
	{
		result.nativeWindow = wmi.info.android.window;
		result.nativeDisplay = nullptr; // wmi.info.android.surface;
	}
	else
#endif // defined(SDL_VIDEO_DRIVER_ANDROID)
	{
		throw std::runtime_error("Unsupported platform or window manager: " + std::to_string(wmi.subsystem));
	}
	return result;
	// clang-format on
}

bool Sdl2WindowingSystem::IsOpen() const
{
	return _window != nullptr;
}

float Sdl2WindowingSystem::GetBrightness() const
{
	return SDL_GetWindowBrightness(_window.get());
}

Sdl2WindowingSystem& Sdl2WindowingSystem::SetBrightness(float brightness)
{
	if (SDL_SetWindowBrightness(_window.get(), brightness) != 0)
	{
		throw std::runtime_error("SDL_SetWindowBrightness Error: " + std::string(SDL_GetError()));
	}
	return *this;
}

uint32_t Sdl2WindowingSystem::GetID() const
{
	return SDL_GetWindowID(_window.get());
}

uint32_t Sdl2WindowingSystem::GetFlags() const
{
	return SDL_GetWindowFlags(_window.get());
}

Sdl2WindowingSystem& Sdl2WindowingSystem::GrabInput(bool b)
{
	SDL_SetWindowGrab(_window.get(), b ? SDL_TRUE : SDL_FALSE);
	return *this;
}

Sdl2WindowingSystem& Sdl2WindowingSystem::SetMousePosition(glm::ivec2 position)
{
	SDL_WarpMouseInWindow(_window.get(), position.x, position.y);
	return *this;
}

bool Sdl2WindowingSystem::IsInputGrabbed() const
{
	return SDL_GetWindowGrab(_window.get()) != SDL_FALSE;
}

std::string Sdl2WindowingSystem::GetTitle() const
{
	return SDL_GetWindowTitle(_window.get());
}

Sdl2WindowingSystem& Sdl2WindowingSystem::SetTitle(const std::string& str)
{
	SDL_SetWindowTitle(_window.get(), str.c_str());
	return *this;
}

float Sdl2WindowingSystem::GetAspectRatio() const
{
	int width;
	int height;
	SDL_GetWindowSize(_window.get(), &width, &height);

	return static_cast<float>(width) / static_cast<float>(height);
}

Sdl2WindowingSystem& Sdl2WindowingSystem::SetPosition(glm::ivec2 position)
{
	SDL_SetWindowPosition(_window.get(), position.x, position.y);
	return *this;
}

glm::ivec2 Sdl2WindowingSystem::GetPosition() const
{
	glm::ivec2 result;
	SDL_GetWindowPosition(_window.get(), &result.x, &result.y);
	return result;
}

Sdl2WindowingSystem& Sdl2WindowingSystem::SetMinimumSize(glm::ivec2 size)
{
	SDL_SetWindowMinimumSize(_window.get(), size.x, size.y);
	return *this;
}

glm::ivec2 Sdl2WindowingSystem::GetMinimumSize() const
{
	glm::ivec2 result;
	SDL_GetWindowMinimumSize(_window.get(), &result.x, &result.y);
	return result;
}

Sdl2WindowingSystem& Sdl2WindowingSystem::SetMaximumSize(glm::ivec2 size)
{
	SDL_SetWindowMaximumSize(_window.get(), size.x, size.y);
	return *this;
}

glm::ivec2 Sdl2WindowingSystem::GetMaximumSize() const
{
	glm::ivec2 result;
	SDL_GetWindowMaximumSize(_window.get(), &result.x, &result.y);
	return result;
}

Sdl2WindowingSystem& Sdl2WindowingSystem::SetSize(glm::ivec2 size)
{
	SDL_SetWindowSize(_window.get(), size.x, size.y);
	return *this;
}

glm::ivec2 Sdl2WindowingSystem::GetSize() const
{
	glm::ivec2 result;
	SDL_GetWindowSize(_window.get(), &result.x, &result.y);
	return result;
}

Sdl2WindowingSystem& Sdl2WindowingSystem::Show()
{
	SDL_ShowWindow(_window.get());
	return *this;
}

Sdl2WindowingSystem& Sdl2WindowingSystem::Hide()
{
	SDL_HideWindow(_window.get());
	return *this;
}

Sdl2WindowingSystem& Sdl2WindowingSystem::Maximise()
{
	SDL_MaximizeWindow(_window.get());
	return *this;
}

Sdl2WindowingSystem& Sdl2WindowingSystem::Minimise()
{
	SDL_MinimizeWindow(_window.get());
	return *this;
}

Sdl2WindowingSystem& Sdl2WindowingSystem::Restore()
{
	SDL_RestoreWindow(_window.get());
	return *this;
}

Sdl2WindowingSystem& Sdl2WindowingSystem::Raise()
{
	SDL_RaiseWindow(_window.get());
	return *this;
}

Sdl2WindowingSystem& Sdl2WindowingSystem::SetBordered(bool b)
{
	SDL_SetWindowBordered(_window.get(), b ? SDL_TRUE : SDL_FALSE);
	return *this;
}

Sdl2WindowingSystem& Sdl2WindowingSystem::SetFullscreen(bool f)
{
	// todo: use DisplayMode
	if (SDL_SetWindowFullscreen(_window.get(), f ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0) != 0)
	{
		throw std::runtime_error("SDL_SetWindowFullscreen Error: " + std::string(SDL_GetError()));
	}
	return *this;
}

Sdl2WindowingSystem& Sdl2WindowingSystem::Close()
{
	_window.reset(nullptr);
	return *this;
}
