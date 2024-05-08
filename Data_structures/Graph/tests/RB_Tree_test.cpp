// #include <RB_Tree.h>
// #include <gtest/gtest.h>
// #include <iostream>
// #include <vector>

// TEST(HeapTest, RB_TreeTest)
// {
//     my::RB_Tree<int> a;

//     for (int i = 3; i < 100; ++i)
//     {
//         a.insert(i);
//     }

//     EXPECT_TRUE(a.check_black_height(a.m_root));
//     EXPECT_TRUE(a.root_color());
//     EXPECT_TRUE(a.check_no_adjacent_red_nodes());

//     for (int i = 0; i < 100; ++i)
//     {
//         try
//         {
//             a.delete_val(i);
//         }
//         catch (const std::out_of_range& ex)
//         {
//             continue;
//         }

//         EXPECT_TRUE(a.check_black_height(a.m_root));
//         EXPECT_TRUE(a.root_color());
//         EXPECT_TRUE(a.check_no_adjacent_red_nodes());
//     }

//     EXPECT_TRUE(a.check_black_height(a.m_root));
//     EXPECT_TRUE(a.root_color());
//     EXPECT_TRUE(a.check_no_adjacent_red_nodes());
// }

// int main(int argc, char** argv)
// {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
