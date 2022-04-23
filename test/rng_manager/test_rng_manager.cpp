/*******************************************************************************
 * Copyright (c) 2018-2022 openblack developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/openblack/openblack
 *
 * openblack is licensed under the GNU General Public License version 3.
 ******************************************************************************/

#include <gtest/gtest.h>

#include <Resources/RNGManager.h>
#include <vector>

#define N_TEST 1000000
#define TEST_SEED 15000


TEST(RngManager, debug_predictable_mono)
{
    openblack::resources::RNGManager& rngmanager = openblack::resources::RNGManager::GetInstance();
    ASSERT_TRUE(rngmanager.SetDebugMode(true, TEST_SEED));

    std::vector<uint16_t> fstResult(N_TEST);
    for (auto it=fstResult.begin(); it!=fstResult.end(); ++it)
    {
        *it = rngmanager.nextInt();
    }

    // Two run with the same seed mush give the same vector.
    ASSERT_TRUE(rngmanager.SetDebugMode(true, TEST_SEED));
    std::vector<uint16_t> sndResult(N_TEST);
    for (auto it=sndResult.begin(); it!=sndResult.end(); ++it)
    {
        *it = rngmanager.nextInt();
    }
    ASSERT_TRUE(fstResult==sndResult);
}

TEST(RngManager, debug_predictable_multi)
{
    openblack::resources::RNGManager& rngmanager = openblack::resources::RNGManager::GetInstance();
    ASSERT_TRUE(rngmanager.SetDebugMode(true, TEST_SEED));

    std::vector<uint16_t> fstResult(N_TEST);
    for (auto it=fstResult.begin(); it!=fstResult.end(); ++it)
    {
        *it = rngmanager.nextInt();
    }

    /*
     * TODO must guarentee that with multiple thread using RNGManager in debug
     * mode will use the same sequence of number.
     */
    ASSERT_TRUE(rngmanager.SetDebugMode(true, TEST_SEED));
    std::vector<uint16_t> sndResult(N_TEST);
    for (auto it=sndResult.begin(); it!=sndResult.end(); ++it)
    {
        *it = rngmanager.nextInt();
    }
    ASSERT_TRUE(fstResult==sndResult);
}