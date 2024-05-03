#include "../headers/RB_Tree.h"

namespace my {
    template <typename T>
    RB_Tree<T>::RB_Tree()
        : m_root(nullptr)
    {
    }

    template <typename T>
    RB_Tree<T>::RB_Tree(typename RB_Tree<T>::const_reference val)
    {
        if (m_root == nullptr)
        {
            m_root = new Node(val, m_nil);
        }
    }

    template <typename T>
    RB_Tree<T>::RB_Tree(std::initializer_list<RB_Tree<T>::value_type>)
        : m_root(nullptr)
    {
    }

    template <typename T>
    RB_Tree<T>::~RB_Tree<T>()
    {
        if (m_root != nullptr)
        {
            destroyTree(m_root);
        }

        delete m_nil;
    }

    //-------------------------_-destroyTree-_-----------------------------//
    template <typename T>
    void RB_Tree<T>::destroyTree(Node* node)
    {
        if (node != m_nil)
        {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    //-------------------------_-left_rotate-_-----------------------------//
    template <typename T>
    typename RB_Tree<T>::Node* RB_Tree<T>::left_rotate(Node* x_node)
    {
        Node* y_node = x_node->right; // Set y_node

        // Turn y_node's left subtree into x_node's right subtree
        x_node->right = y_node->left;
        if (y_node->left != m_nil)
        {
            y_node->left->parent = x_node;
        }

        // Link x_node's parent to y_node
        y_node->parent = x_node->parent;
        if (x_node->parent == m_nil)
        {
            m_root = y_node;
        }
        else if (x_node == x_node->parent->left)
        {
            x_node->parent->left = y_node;
        }
        else
        {
            x_node->parent->right = y_node;
        }
        // Put x_node on y_node's left
        y_node->left   = x_node;
        x_node->parent = y_node;

        return y_node;
    }

    //-------------------------_-left_rotate-_-----------------------------//
    template <typename T>
    typename RB_Tree<T>::Node* RB_Tree<T>::right_rotate(Node* x_node)
    {
        Node* y_node = x_node->right; // Set y_node

        
    }

} // namespace my
