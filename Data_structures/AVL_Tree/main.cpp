#include <AVL_Tree.h>

int main()
{
    // Create the source AVL tree
    my::AVL_tree<int> avl = {
        1, 2, 3, 4, 5, 6, 7, 8, 9,
    };

    // Insert additional elements into the source tree
    for (int i = 10; i < 25; ++i)
    {
        avl.insert(i);
    }

    avl.levelOrderTraversal();

    // Create a target AVL tree using move constructor
    my::AVL_tree<int> targetTreeMoveConstructor(std::move(avl));

    std::cout << "Target tree (move constructor):" << std::endl;
    targetTreeMoveConstructor.levelOrderTraversal();

    // Create another target AVL tree using move assignment
    my::AVL_tree<int> targetTreeMoveAssignment;
    targetTreeMoveAssignment = std::move(targetTreeMoveConstructor);

    // Now 'avl' should be empty as its resources have been moved
    std::cout << "Source tree (after move):" << std::endl;
    avl.levelOrderTraversal(); // Should print an empty tree

    // Print the target tree created using move constructor

    // Print the target tree created using move assignment
    std::cout << "Target tree (move assignment):" << std::endl;
    targetTreeMoveAssignment.levelOrderTraversal();

    return 0;
}