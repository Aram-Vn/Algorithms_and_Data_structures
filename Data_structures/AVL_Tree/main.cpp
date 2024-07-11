#include <AVL_Tree.h>

int main()
{
    my::AVL_tree<int> avl = {
        1, 2, 3, 4, 5, 6, 7, 8, 9,
    };

    my::AVL_tree<int> t2 = avl;

    avl.levelOrderTraversal();

    for (int i = 10; i < 25; ++i)
    {
        avl.insert(i);
    }

    // avl.levelOrderTraversal();

    // my::AVL_tree<int> targetTreeMoveConstructor(std::move(avl));

    // std::cout << "Target tree (move constructor):" << std::endl;
    // targetTreeMoveConstructor.levelOrderTraversal();

    // my::AVL_tree<int> targetTreeMoveAssignment;
    // targetTreeMoveAssignment = std::move(targetTreeMoveConstructor);

    // std::cout << "Source tree (after move):" << std::endl;
    // avl.levelOrderTraversal(); // Should print an empty tree

    // std::cout << "Target tree (move assignment):" << std::endl;
    // targetTreeMoveAssignment.levelOrderTraversal();

    // std::cout << targetTreeMoveAssignment.findMax() << std::endl;

    // return 0;
}