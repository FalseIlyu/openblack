/******************************************************************************
 * Copyright (c) 2018-2024 openblack developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/openblack/openblack
 *
 * openblack is licensed under the GNU General Public License version 3.
 *******************************************************************************/

#pragma once

#include "ShaderManagerInterface.h"

#if !defined(LOCATOR_IMPLEMENTATIONS)
#error "Locator interface implementations should only be included in Locator.cpp, use interface instead."
#endif

namespace openblack
{

class Camera;

namespace graphics
{

class ShaderManager final: public ShaderManagerInterface
{
public:
	ShaderManager() = default;
	~ShaderManager();

	void LoadShaders();
	[[nodiscard]] const ShaderProgram* GetShader(const std::string& name) const;

	void SetCamera(RenderPass viewId, const Camera& camera);

private:
	using ShaderMap = std::map<std::string, const ShaderProgram*>;

	ShaderMap _shaderPrograms;
};

} // namespace graphics
} // namespace openblack
