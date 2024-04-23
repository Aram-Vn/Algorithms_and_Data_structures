#include <Binary_Search_Tree.h>

int main()
{

    BST<int> bst = { 60, 50, 70, 40, 55, 65, 80, 30, 45, 53, 58, 63, 68, 75, 90, 20, 35, 42 };

    std::cout << "Inorder Traversal: \n";
    bst.inorderTraversal();
    bst.postTraversal();
    bst.preTraversal();
    bst.levelOrderTraversal();

    std::cout << bst.getSuccessor(40) << std::endl;
    std::cout << bst.getPredecessor(40) << std::endl;
    int searchValue = 6;
    if (bst.search(searchValue))
    {
        std::cout << searchValue << " found in the BST.\n";
    }
    else
    {
        std::cout << searchValue << " not found in the BST.\n";
    }

    std::cout << bst.find_min() << std::endl;
    std::cout << bst.find_max() << std::endl;
    bst.Delete(70);
    bst.Delete(50);

    std::cout << "\nBST after deletion: 50 70" << std::endl;
    bst.inorderTraversal();

    searchValue = 10;
    if (bst.search(searchValue))
    {
        std::cout << searchValue << " found in the BST.\n";
    }
    else
    {
        std::cout << searchValue << " not found in the BST.\n";
    }

    std::cout << bst.getHeight() << std::endl;
    return 0;
}
