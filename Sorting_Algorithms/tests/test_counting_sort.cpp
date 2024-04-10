#include "../include/counting_sort.h"
#include <gtest/gtest.h>

class CountingSortTest : public ::testing::Test
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

    bool isSorted(const std::vector<int> &vec)
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

    const size_t size            = 90000;
    const size_t range           = 5000;
    bool         useSpecificSeed = false;
    size_t       specificSeed    = 465489480787;
};

TEST_F(CountingSortTest, SortsVectorCorrectlyWith__RandomSeed)
{
    useSpecificSeed = false;

    std::vector<int> unsorted;

    for (size_t i = 0; i < size; ++i)
    {
        unsorted.push_back(rand() % 10000 - range);
    }

    counting_sort(unsorted);

    EXPECT_TRUE(isSorted(unsorted));
}

TEST_F(CountingSortTest, SortsVectorCorrectlyWith__SpecificSeed)
{
    useSpecificSeed = true;

    std::vector<int> unsorted;

    for (size_t i = 0; i < size; ++i)
    {
        unsorted.push_back(rand() % 10000 - range);
    }

    counting_sort(unsorted);

    EXPECT_TRUE(isSorted(unsorted));
}

TEST_F(CountingSortTest, SortsVectorCorrectlyWith__DescendingOrderVector)
{
    std::vector<int> descending(size);

    for (size_t i = size; i > 0; --i)
    {
        descending[size - i] = i;
    }

    counting_sort(descending);

    EXPECT_TRUE(isSorted(descending));
}

TEST_F(CountingSortTest, Handles__EmptyVector)
{
    std::vector<int> empty;

    counting_sort(empty);

    EXPECT_EQ(empty.size(), 0);
}

TEST_F(CountingSortTest, Handles__AlreadySortedVector)
{
    std::vector<int> sorted(size);
    for (size_t i = 0; i < size; ++i)
    {
        sorted[i] = i;
    }

    counting_sort(sorted);

    EXPECT_TRUE(isSorted(sorted));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
