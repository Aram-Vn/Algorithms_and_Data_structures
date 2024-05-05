#include "iostream"
#include <RB_Tree.h>

int main()
{
    // my::RB_Tree<int> a;
    my::RB_Tree<int> a;

    for (int i = 0; i < 18; ++i)
    {
        a.insert(i);
    }
    a.level_order_traversal();
}
