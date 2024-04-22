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
    void     insert(const T& value);
    bool     search(const T& value) const;
    void     inorderTraversal() const;
    void     Delete(const T& val);
    const T& find_min() const;
    const T& find_max() const;

private:
    void                  insert(std::unique_ptr<Node>& node, const T& value);
    void                  inorderTraversal(const std::unique_ptr<Node>& node) const;
    bool                  search(const std::unique_ptr<Node>& node, const T& value) const;
    std::unique_ptr<Node> Delete(const T& val, std::unique_ptr<Node> root);
    Node*                 find_min(Node* root) const;
    Node*                 find_max(Node* root) const;

private:
    std::unique_ptr<Node> m_root;
};

#include "Binary_Search_Tree.hpp"
