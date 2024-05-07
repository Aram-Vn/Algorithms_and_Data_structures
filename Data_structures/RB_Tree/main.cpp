// #include "iostream"
#include <RB_Tree.h>

int main()
{
    my::RB_Tree<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    // my::RB_Tree<int> a = { 1, 2, 3, 4, 5, 6, 7, 8 };

    // a.inorder_traversal();
    // a.level_order_traversal();
    a.display();

    if (a.check_black_height() && a.root_color() && a.check_no_adjacent_red_nodes())
    {
        std::cout << "yes" << std::endl;
        std::cout << std::endl;
    }
    else
    {
        std::cout << "NO!!!!!" << std::endl;
        std::cout << std::endl;
    }

    a.delete_val(2);
    a.delete_val(1);
    

    if (a.check_black_height() && a.root_color() && a.check_no_adjacent_red_nodes())
    {
        std::cout << "yes" << std::endl;
        std::cout << std::endl;
    }
    else
    {
        std::cout << "NO!!!!!" << std::endl;
        std::cout << std::endl;
    }

    a.display();
    // a.level_order_traversal();
    // a.inorder_traversal();
    std::cout << a.get_minVal() << std::endl;
}