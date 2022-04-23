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
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

#define N_TEST 100
#define TEST_SEED 15000
#define N_THREAD 10


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

void randomThread(int totalIteration, int& counter, std::vector<uint16_t>& result, std::mutex& lock) 
{
    openblack::resources::RNGManager& rngmanager = openblack::resources::RNGManager::GetInstance();
    
    for (int i = 0; i < totalIteration; i++)
    {
        uint16_t random = rngmanager.nextInt();
        {
            std::lock_guard<std::mutex> locked(lock);
            std::cout << counter << ": ";
            std::cout << random << std::endl;
            result[counter] = random;
            counter++;
        }
    }
};

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
    int index = 0;
    int item_per_thread = N_TEST / N_THREAD;
    std::vector<uint16_t> sndResult(N_TEST);
    std::vector<std::thread> thread_vector;
    std::mutex lock;
    for (int i = 0; i < N_THREAD; i++)
    {
        auto l = [item_per_thread, &index, &sndResult, &lock] { randomThread(item_per_thread, index, sndResult, lock); };
        thread_vector.push_back(std::thread(l));
    }
    for (auto t = thread_vector.begin(); t != thread_vector.end(); ++t)
    {
        t ->join();
    }

    ASSERT_TRUE(fstResult==sndResult);
}