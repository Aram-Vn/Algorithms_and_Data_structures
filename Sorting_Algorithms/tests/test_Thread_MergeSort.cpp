#include "../include/Thread_MergeSort.h"

#include <gtest/gtest.h>

class Thread_SelectionSortTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        if (useSpecificSeed)
        {
            srand(specificSeed);
        }
        else
        {
            srand(time(0));
        }
    }

    bool isSorted(const std::vector<int>& vec)
    {
        for (size_t i = 0; i < vec.size() - 1; ++i)
        {
            if (vec[i] > vec[i + 1])
            {
                return false;
            }
        }
        return true;
    }

    unsigned int max_threads     = std::thread::hardware_concurrency();
    int          depth           = 4;
    const size_t size            = 9000000;
    const size_t range           = 5000;
    bool         useSpecificSeed = false;
    size_t       specificSeed    = 465489480787;
};

TEST_F(Thread_SelectionSortTest, SortsVectorCorrectlyWith__RandomSeed)
{
    useSpecificSeed = false;
    std::vector<int> arr;

    for (size_t i = 0; i < size; ++i)
    {
        arr.push_back(rand() % 10000 - range);
    }

    if (depth > max_threads)
    {
        depth = 4;
    }

    int arr_size = arr.size();

    mergeSort(arr, 0, arr_size - 1, depth);

    EXPECT_TRUE(isSorted(arr));
}

TEST_F(Thread_SelectionSortTest, SortsVectorCorrectlyWith__SpecificSeed)
{
    useSpecificSeed = true;

    std::vector<int> arr;

    for (size_t i = 0; i < size; ++i)
    {
        arr.push_back(rand() % 10000 - range);
    }

    if (depth > max_threads)
    {
        depth = 4;
    }

    int arr_size = arr.size();
    mergeSort(arr, 0, arr_size - 1, depth);

    EXPECT_TRUE(isSorted(arr));
}

TEST_F(Thread_SelectionSortTest, SortsVectorCorrectlyWith__DescendingOrderVector)
{
    std::vector<int> descending(size);

    for (size_t i = size; i > 0; --i)
    {
        descending[size - i] = i;
    }

    if (depth > max_threads)
    {
        depth = 4;
    }

    int arr_size = descending.size();
    mergeSort(descending, 0, arr_size - 1, depth);

    EXPECT_TRUE(isSorted(descending));
}

TEST_F(Thread_SelectionSortTest, Handles__EmptyVector)
{
    std::vector<int> empty;

    if (depth > max_threads)
    {
        depth = 4;
    }

    mergeSort(empty, 0, empty.size() - 1, depth);

    EXPECT_EQ(empty.size(), 0);
}

TEST_F(Thread_SelectionSortTest, Handles__AlreadySortedVector)
{
    std::vector<int> sorted(size);
    for (size_t i = 0; i < size; ++i)
    {
        sorted[i] = i;
    }

    if (depth > max_threads)
    {
        depth = 4;
    }

    mergeSort(sorted, 0, sorted.size() - 1, depth);

    EXPECT_TRUE(isSorted(sorted));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
