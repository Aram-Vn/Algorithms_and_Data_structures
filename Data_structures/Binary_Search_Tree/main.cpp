#include <Binary_Search_Tree.h>

#include "Binary_Search_Tree.h"

int main()
{
    // Create an instance of BST
    my::BST<int> original;

    // Insert some values into the original BST
    original.insert(50);
    original.insert(30);
    original.insert(70);
    original.insert(20);
    original.insert(40);
    original.insert(60);
    original.insert(80);

    // Create a new BST by moving from the original BST (move constructor)
    my::BST<int> moved(std::move(original));

    // Print the elements of the moved BST
    std::cout << "Moved BST:" << std::endl;
    moved.inorderTraversal();
    std::cout << std::endl;

    // Attempt to access elements of the original BST (should produce undefined behavior)
    std::cout << "Original BST after moving:" << std::endl;
    original.inorderTraversal(); // This should produce undefined behavior

    // Create another instance and use the move assignment operator
    my::BST<int> assigned;
    assigned = std::move(moved);

    // Print the elements of the assigned BST
    std::cout << "Assigned BST:" << std::endl;
    assigned.inorderTraversal();
    std::cout << std::endl;

    // Print the elements of the moved BST (should be in a valid but unspecified state)
    std::cout << "Moved BST after moving:" << std::endl;
    moved.inorderTraversal(); // This should produce an empty traversal

    return 0;
}
