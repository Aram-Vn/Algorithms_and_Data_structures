#include <iostream>
#include <memory>

template <typename T>
BST<T>::BST()
    : root(nullptr)
{
}

template <typename T>
void BST<T>::insert(const T& value)
{
    insert(root, value);
}

template <typename T>
void BST<T>::insert(std::unique_ptr<Node>& node, const T& value)
{
    if (!node)
    {
        node = std::make_unique<Node>(value);
    }
    else
    {
        if (value < node->val)
        {
            insert(node->left, value);
        }
        else
        {
            insert(node->right, value);
        }
    }
}

template <typename T>
void BST<T>::inorderTraversal() const
{
    inorderTraversal(root);
    std::cout << std::endl;
}

template <typename T>
void BST<T>::inorderTraversal(const std::unique_ptr<Node>& node) const
{
    if (node)
    {
        inorderTraversal(node->left);
        std::cout << node->val << " ";
        inorderTraversal(node->right);
    }
}

template <typename T>
bool BST<T>::search(const T& value) const
{
    return search(root, value);
}

template <typename T>
bool BST<T>::search(const std::unique_ptr<Node>& node, const T& value) const
{
    if (!node)
    {
        return false;
    }
    if (node->val == value)
    {
        return true;
    }
    else if (value < node->val)
    {
        return search(node->left, value);
    }
    else
    {
        return search(node->right, value);
    }
}
