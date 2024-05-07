#include <Binary_Search_Tree.h>

#include "Binary_Search_Tree.h"

int main()
{
    // Create an instance of BST
    my::BST<int> original;

    for (int i = 0; i < 15; ++i)
    {
        original.insert(i);
    }

    original.levelOrderTraversal();
}
