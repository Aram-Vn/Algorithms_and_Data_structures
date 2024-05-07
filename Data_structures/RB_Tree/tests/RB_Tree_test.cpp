#include <RB_Tree.h>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>

TEST(HeapTest, RB_TreeTest)
{
    my::RB_Tree<int> a = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    EXPECT_TRUE(a.check_black_height(a.get_root()));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
