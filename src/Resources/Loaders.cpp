/*****************************************************************************
 * Copyright (c) 2018-2022 openblack developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/openblack/openblack
 *
 * openblack is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "Resources/Loaders.h"

using namespace openblack;
using namespace openblack::resources;

entt::resource_handle<L3DMesh> L3DLoader::load(const std::string& debugName, const std::vector<uint8_t>& data) const
{
	auto mesh = std::make_shared<L3DMesh>(debugName);
	if (!mesh->LoadFromBuffer(data))
	{
		throw std::runtime_error("Unable to load mesh");
	}

	return mesh;
}

entt::resource_handle<L3DMesh> L3DLoader::load(const std::string& debugName, const std::filesystem::path& path) const
{
	auto mesh = std::make_shared<L3DMesh>(debugName);
	if (!mesh->LoadFromFile(path))
	{
		throw std::runtime_error("Unable to load mesh");
	}

	return mesh;
}

entt::resource_handle<graphics::Texture2D> Texture2DLoader::load(const std::string& name,
                                                                 const pack::G3DTexture g3dTexture) const
{
	// some assumptions:
	// - no mipmaps
	// - no cubemap or volume textures
	// - always dxt1 or dxt3
	// - all are compressed
	auto texture2D = std::make_shared<graphics::Texture2D>(name);
	graphics::Format internalFormat;
	if (g3dTexture.ddsHeader.format.fourCC == std::string("DXT1"))
		internalFormat = graphics::Format::BlockCompression1;
	else if (g3dTexture.ddsHeader.format.fourCC == std::string("DXT3"))
		internalFormat = graphics::Format::BlockCompression2;
	else if (g3dTexture.ddsHeader.format.fourCC == std::string("DXT5"))
		internalFormat = graphics::Format::BlockCompression3;
	else
		throw std::runtime_error("Unsupported compressed texture format");

	texture2D->Create(static_cast<uint16_t>(g3dTexture.ddsHeader.width), static_cast<uint16_t>(g3dTexture.ddsHeader.height), 1,
	                  internalFormat, graphics::Wrapping::Repeat, g3dTexture.ddsData.data(),
	                  static_cast<uint32_t>(g3dTexture.ddsData.size()));
	return texture2D;
}

entt::resource_handle<L3DAnim> L3DAnimLoader::load(const std::vector<uint8_t>& data) const
{
	auto animation = std::make_shared<L3DAnim>();
	animation->LoadFromBuffer(data);
	return animation;
}

entt::resource_handle<L3DAnim> L3DAnimLoader::load(const std::filesystem::path& path) const
{
	auto animation = std::make_shared<L3DAnim>();
	if (!animation->LoadFromFile(path))
	{
		throw std::runtime_error("Unable to load animation");
	}

	return animation;
}
