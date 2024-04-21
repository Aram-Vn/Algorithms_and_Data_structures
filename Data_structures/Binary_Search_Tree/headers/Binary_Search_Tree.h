#include <iostream>
#include <memory>

template <class T>
class BST
{
public:
    struct Node
    {
        T                     val;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

        Node(const T& value)
            : val(value),
              left(nullptr),
              right(nullptr)
        {
        }
    };

public:
    BST();

public:
    void insert(const T& value);
    bool search(const T& value) const;
    void inorderTraversal() const;

private:
    void insert(std::unique_ptr<Node>& node, const T& value);
    void inorderTraversal(const std::unique_ptr<Node>& node) const;
    bool search(const std::unique_ptr<Node>& node, const T& value) const;

private:
    std::unique_ptr<Node> root;
};

#include "Binary_Search_Tree.hpp"
