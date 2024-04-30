#include <functional>
#include <gtest/gtest.h>
#include <iostream>
#include <priority_queue.h>
#include <sstream>
#include <vector>

TEST(HeapTest, MinHeap_validConvertintToheap)
{
    std::vector<int>        data = { 9, 7, 5, 11, 12, 2, 14, 3, 10, 6 };
    my::priority_queue<int> MinHeap(data);
    std::vector<int>        expected = {
        2, 3, 5, 7, 6, 9, 14, 11, 10, 12,
    };
    std::vector<int> outputVec;
    int              element;

    testing::internal::CaptureStdout();
    MinHeap.print();

    std::string        output = testing::internal::GetCapturedStdout();
    std::istringstream local(output);

    while (local >> element)
    {
        outputVec.push_back(element);
    }

    ASSERT_EQ(expected, outputVec);
    ASSERT_TRUE(MinHeap.is_valid_heap());
}

TEST(HeapTest, MaxHeap_validConvertintToheap)
{
    std::vector<int>                           data = { 9, 7, 5, 11, 12, 2, 14, 3, 10, 6 };
    my::priority_queue<int, std::greater<int>> MaxHeap(data);
    std::vector<int>                           expected = { 14, 12, 9, 11, 7, 2, 5, 3, 10, 6 };
    std::vector<int>                           outputVec;
    int                                        element;

    testing::internal::CaptureStdout();
    MaxHeap.print();

    std::string        output = testing::internal::GetCapturedStdout();
    std::istringstream local(output);

    while (local >> element)
    {
        outputVec.push_back(element);
    }

    ASSERT_EQ(expected, outputVec);
    ASSERT_TRUE(MaxHeap.is_valid_heap());
}

TEST(HeapTest, MinHeap_topTest)
{
    std::vector<int>        data = { 10, 7, 5, 11, 12, 2, 14, 20, 10, 66 };
    my::priority_queue<int> MinHeap(data);

    ASSERT_EQ(MinHeap.top(), 2);
    ASSERT_TRUE(MinHeap.is_valid_heap());
}

TEST(HeapTest, MaxHeap_topTest)
{
    std::vector<int>                           data = { 9, 11, 5, 11, 14, 2, 1, 3, 0, 6 };
    my::priority_queue<int, std::greater<int>> MaxHeap(data);

    ASSERT_EQ(MaxHeap.top(), 14);
    ASSERT_TRUE(MaxHeap.is_valid_heap());
}

TEST(HeapTest, MaxHeap_Push_PopTest)
{
    my::priority_queue<int, std::greater<int>> MaxHeap;
    MaxHeap.push(3);
    MaxHeap.push(2);
    MaxHeap.push(4);
    MaxHeap.push(1);
    MaxHeap.push(0);
    MaxHeap.push(5);
    MaxHeap.push(9);

    ASSERT_EQ(MaxHeap.top(), 9);
    ASSERT_TRUE(MaxHeap.is_valid_heap());

    MaxHeap.pop();
    ASSERT_EQ(MaxHeap.top(), 5);
    ASSERT_TRUE(MaxHeap.is_valid_heap());

    MaxHeap.pop();
    ASSERT_EQ(MaxHeap.top(), 4);
    ASSERT_TRUE(MaxHeap.is_valid_heap());

    MaxHeap.pop();
    ASSERT_EQ(MaxHeap.top(), 3);
    ASSERT_TRUE(MaxHeap.is_valid_heap());

    MaxHeap.pop();
    ASSERT_EQ(MaxHeap.top(), 2);
    ASSERT_TRUE(MaxHeap.is_valid_heap());

    MaxHeap.pop();
    ASSERT_EQ(MaxHeap.top(), 1);
    ASSERT_TRUE(MaxHeap.is_valid_heap());
}

TEST(HeapTest, MinHeap_Push_PopTest)
{
    my::priority_queue<int> MinHeap;
    MinHeap.push(3);
    MinHeap.push(2);
    MinHeap.push(4);
    MinHeap.push(1);
    MinHeap.push(5);
    MinHeap.push(9);

    ASSERT_EQ(MinHeap.top(), 1);
    ASSERT_TRUE(MinHeap.is_valid_heap());

    MinHeap.pop();
    ASSERT_EQ(MinHeap.top(), 2);
    ASSERT_TRUE(MinHeap.is_valid_heap());

    MinHeap.pop();
    ASSERT_EQ(MinHeap.top(), 3);
    ASSERT_TRUE(MinHeap.is_valid_heap());

    MinHeap.pop();
    ASSERT_EQ(MinHeap.top(), 4);
    ASSERT_TRUE(MinHeap.is_valid_heap());

    MinHeap.pop();
    ASSERT_EQ(MinHeap.top(), 5);
    ASSERT_TRUE(MinHeap.is_valid_heap());

    MinHeap.pop();
    ASSERT_EQ(MinHeap.top(), 9);
    ASSERT_TRUE(MinHeap.is_valid_heap());
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
