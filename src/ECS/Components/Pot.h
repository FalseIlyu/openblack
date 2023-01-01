/*****************************************************************************
 * Copyright (c) 2018-2023 openblack developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/openblack/openblack
 *
 * openblack is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include <cstdint>

namespace openblack::ecs::components
{

struct Pot
{
	uint16_t amount;
	uint16_t maxAmount;
};

} // namespace openblack::ecs::components
