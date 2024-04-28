#include <AVL_Tree.h>

int main()
{
    my::AVL_tree<int> avl = {
        1, 2, 3, 4, 5, 6, 7, 8, 9,
    };

    for (int i = 0; i < 25; ++i)
    {
        avl.insert(i);
    }

    avl.DeleteNode(10);
    avl.DeleteNode(11);
    avl.DeleteNode(1);
    avl.levelOrderTraversal();
    avl.inOrder();
    avl.postOrder();
    avl.preOrder();

    avl.clear();
    std::cout << avl.getHeight() << std::endl;
}