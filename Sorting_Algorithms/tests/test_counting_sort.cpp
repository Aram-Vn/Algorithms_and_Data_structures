#include "../include/counting_sort.h"
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <gtest/gtest.h>

// Define test cases
TEST(CountingSortTest, SortsVectorCorrectly)
{
    srand(time(0));

    std::vector<int> unsorted;
    const size_t size = 90000;
    for (size_t i = 0; i < size; ++i)
    {
        unsorted.push_back(rand() % 10000 - 5000);
    }

    counting_sort(unsorted);

    for (size_t i = 0; i < unsorted.size() - 1; ++i)
    {
        EXPECT_LE(unsorted[i], unsorted[i + 1]);
    }
}

TEST(CountingSortTest, HandlesEmptyVector)
{
    std::vector<int> empty;
    counting_sort(empty);
    EXPECT_EQ(empty.size(), 0);
}

TEST(CountingSortTest, HandlesAlreadySortedVector)
{
    std::vector<int> sorted;
    for (int i = 0; i < 90000; ++i)
    {
        sorted.push_back(i);
    }

    counting_sort(sorted);

    for (size_t i = 0; i < sorted.size() - 1; ++i)
    {
        EXPECT_LE(sorted[i], sorted[i + 1]);
    }
}

TEST(CountingSortTest, HandlesDescendingOrderVector)
{
    std::vector<int> descending;
    for (int i = 90000; i > 0; --i)
    {
        descending.push_back(i);
    }

    counting_sort(descending);

    for (size_t i = 0; i < descending.size() - 1; ++i)
    {
        EXPECT_LE(descending[i], descending[i + 1]);
    }
}

int main(int argc, char** argv)
{
    srand(time(0));
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}