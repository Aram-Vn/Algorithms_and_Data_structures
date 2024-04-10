#include <gtest/gtest.h>
#include <heap.h>

TEST(HeapTest, MinHeap_top_test)
{

    std::vector<int> data = { 9, 7, 5, 11, 12, 2, 14, 3, 10, 6 };
    my::Heap<int>    heap(data);

    ASSERT_EQ(heap.top(), 2);
}

TEST(HeapTest, MaxHeap_Push_PopTest)
{
    my::Heap<int, std::greater<int>> heap;
    heap.push(3);
    heap.push(2);
    heap.push(4);
    heap.push(1);
    heap.push(5);
    heap.push(9);

    ASSERT_EQ(heap.top(), 9);

    heap.pop();
    ASSERT_EQ(heap.top(), 5);

    heap.pop();
    ASSERT_EQ(heap.top(), 4);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
