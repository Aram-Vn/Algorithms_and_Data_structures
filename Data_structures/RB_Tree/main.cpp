// #include "iostream"
#include <RB_Tree.h>

int main()
{
    // int j = 5;
    // my::RB_Tree<int> a;
    my::RB_Tree<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};

    // for (int i = 0; i < 5; ++i)
    // {
    //     std::cout << i << std::endl;
    //     a.insert(i);
    // }
    a.level_order_traversal();
    std::cout << a.get_minVal() << std::endl;
}