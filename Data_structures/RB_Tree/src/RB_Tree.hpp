#include "../headers/RB_Tree.h"

namespace my {
    template <typename T>
    RB_Tree<T>::RB_Tree(const T& val)
    {
        if (m_root == nullptr)
        {
            m_root         = new Node(val);
            m_root->parent = m_nil;
            m_root->left   = m_nil;
            m_root->right  = m_nil;
        }
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

} // namespace my
