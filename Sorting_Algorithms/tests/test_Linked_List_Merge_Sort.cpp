#include "../include/Linked_List_Merge_Sort.h"
#include <gtest/gtest.h>

class MergeSortTest : public ::testing::Test
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

    bool isSorted(const Forward_list& list)
    {
        Forward_list::Node* current = list.m_head;
        while (current != nullptr && current->next != nullptr)
        {
            if (current->data > current->next->data)
            {
                return false;
            }
            current = current->next;
        }
        return true;
    }

    const size_t size            = 90000;
    const size_t range           = 5000;
    bool         useSpecificSeed = false;
    size_t       specificSeed    = 465489480787;
};

TEST_F(MergeSortTest, SortsListCorrectly__RandomSeed)
{
    useSpecificSeed = false;

    Forward_list unsortedList;

    for (size_t i = 0; i < size; ++i)
    {
        unsortedList.push(rand() % 10000 - range);
    }

    unsortedList.MergeSort();

    EXPECT_TRUE(isSorted(unsortedList));
}

TEST_F(MergeSortTest, SortsListCorrectly__SpecificSeed)
{
    useSpecificSeed = true;

    Forward_list unsortedList;

    for (size_t i = 0; i < size; ++i)
    {
        unsortedList.push(rand() % 10000 - range);
    }

    unsortedList.MergeSort();

    EXPECT_TRUE(isSorted(unsortedList));
}

TEST_F(MergeSortTest, SortsListCorrectly__DescendingOrder)
{
    Forward_list descending;

    for (size_t i = size; i > 0; --i)
    {
        descending.push(i);
    }

    descending.MergeSort();

    EXPECT_TRUE(isSorted(descending));
}

TEST_F(MergeSortTest, SortsListCorrectly__AlreadySorted)
{
    Forward_list sorted;
    for (size_t i = 0; i < size; ++i)
    {
        sorted.push(i);
    }

    sorted.MergeSort();

    EXPECT_TRUE(isSorted(sorted));
}

TEST_F(MergeSortTest, Handles__EmptyList)
{
    Forward_list empty_list;

    empty_list.MergeSort();

    EXPECT_TRUE(isSorted(empty_list));
}

TEST_F(MergeSortTest, Handles__SingleElement)
{
    Forward_list single_element_list = { 42 };

    single_element_list.MergeSort();

    EXPECT_TRUE(isSorted(single_element_list));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
