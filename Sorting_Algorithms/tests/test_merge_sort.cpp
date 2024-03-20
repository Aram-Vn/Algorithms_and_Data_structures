#include "../include/merge_sort.h"
#include <cstdlib>
#include <ctime>
#include <gtest/gtest.h>
#include <vector>

TEST(mergeSortTest, SortsVecCorrectly)
{
    srand(time(0));

    std::vector<int> unsorted;
    const size_t size = 90000;
    for (size_t i = 0; i < size; ++i)
    {
        unsorted.push_back(rand() % 100);
    }

    mergeSort(unsorted);

    for (size_t i = 0; i < unsorted.size() - 1; ++i)
    {
        EXPECT_LE(unsorted[i], unsorted[i + 1]);
    }
}

TEST(mergeSortTest, HandlesEmptyVector)
{
    std::vector<int> empty;
    mergeSort(empty);
    EXPECT_EQ(empty.size(), 0);
}

TEST(mergeSortTest, HandlesAlreadySortedVector)
{
    std::vector<int> sorted;
    for (int i = 0; i < 90000; ++i)
    {
        sorted.push_back(i);
    }

    mergeSort(sorted);

    for (size_t i = 0; i < sorted.size() - 1; ++i)
    {
        EXPECT_LE(sorted[i], sorted[i + 1]);
    }
}

TEST(mergeSortTest, HandlesDescendingOrderVector)
{
    std::vector<int> descending;
    for (int i = 90000; i > 0; --i)
    {
        descending.push_back(i);
    }

    mergeSort(descending);

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