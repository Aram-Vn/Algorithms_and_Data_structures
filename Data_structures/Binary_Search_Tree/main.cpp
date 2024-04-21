#include <Binary_Search_Tree.h>

int main()
{
    BST<int> bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    std::cout << "Inorder Traversal: ";
    bst.inorderTraversal();

    int searchValue = 6;
    if (bst.search(searchValue))
    {
        std::cout << searchValue << " found in the BST.\n";
    }
    else
    {
        std::cout << searchValue << " not found in the BST.\n";
    }

    searchValue = 10;
    if (bst.search(searchValue))
    {
        std::cout << searchValue << " found in the BST.\n";
    }
    else
    {
        std::cout << searchValue << " not found in the BST.\n";
    }

    return 0;
}
