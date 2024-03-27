#include "../include/insertion_sort.h"
#include <cstdlib>
#include <ctime>
#include <gtest/gtest.h>
#include <vector>

class InsertionSortTest : public ::testing::Test
{
protected:
    void SetUp() override { srand(time(0)); }

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

    const size_t size = 90000;
};

TEST_F(InsertionSortTest, SortsVectorCorrectly)
{

    std::vector<int> unsorted;

    for (size_t i = 0; i < size; ++i)
    {
        unsorted.push_back(rand() % 10000 - 5000);
    }

    insertion_sort(unsorted);

    EXPECT_TRUE(isSorted(unsorted));
}

TEST_F(InsertionSortTest, HandlesEmptyVector)
{
    std::vector<int> empty;

    insertion_sort(empty);

    EXPECT_EQ(empty.size(), 0);
}

TEST_F(InsertionSortTest, HandlesAlreadySortedVector)
{
    std::vector<int> sorted(size);
    for (size_t i = 0; i < size; ++i)
    {
        sorted[i] = i;
    }

    insertion_sort(sorted);

    EXPECT_TRUE(isSorted(sorted));
}

TEST_F(InsertionSortTest, HandlesDescendingOrderVector)
{
    std::vector<int> descending(size);

    for (size_t i = size; i > 0; --i)
    {
        descending[size - i] = i;
    }

    insertion_sort(descending);

    EXPECT_TRUE(isSorted(descending));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
