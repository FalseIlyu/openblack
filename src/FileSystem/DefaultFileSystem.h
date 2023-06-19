/******************************************************************************
 * Copyright (c) 2018-2023 openblack developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/openblack/openblack
 *
 * openblack is licensed under the GNU General Public License version 3.
 *******************************************************************************/

#pragma once

#include <vector>

#include "FileSystemInterface.h"

namespace openblack::filesystem
{

class DefaultFileSystem: public FileSystemInterface
{
public:
	[[nodiscard]] std::filesystem::path FindPath(const std::filesystem::path& path) const override;
	std::unique_ptr<Stream> Open(const std::filesystem::path& path, Stream::Mode mode) override;
	bool Exists(const std::filesystem::path& path) const override;
	void SetGamePath(const std::filesystem::path& path) override { _gamePath = path; }
	[[nodiscard]] const std::filesystem::path& GetGamePath() const override { return _gamePath; }
	void AddAdditionalPath(const std::filesystem::path& path) override { _additionalPaths.push_back(path); }
	std::vector<uint8_t> ReadAll(const std::filesystem::path& path) override;

private:
	std::filesystem::path _gamePath;
	std::vector<std::filesystem::path> _additionalPaths;
};

} // namespace openblack::filesystem
