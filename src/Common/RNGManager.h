/*****************************************************************************
 * Copyright (c) 2018-2022 openblack developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/openblack/openblack
 *
 * openblack is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include "rng.h"

namespace openblack
{
class RNGManager final: public RNGInterface<std::mt19937>
{
public:
	RNGManager();
	bool SetDebugMode(bool is_debug, int seed);
	RNGManager(const RNGManager&) = delete;
	RNGManager& operator=(const RNGManager&) = delete;
};
} // namespace openblack
