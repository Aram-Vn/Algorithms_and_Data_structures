#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <initializer_list>
#include <iostream>
#include <queue>
#include <vector>

namespace my {

    template <typename T>
    class AVL_tree
    {
    private:
        struct Node
        {
            T     val;
            Node* left;
            Node* right;

            Node(const T& value)
                : val(value),
                  left(nullptr),
                  right(nullptr)
            {
            }
        };

    public:
        AVL_tree();
        AVL_tree(std::initializer_list<T> init_list);
        ~AVL_tree();

    public:
        void                        insert(const T& val);
        std::size_t                 getHeight() const;
        void                        clear();
        void                        print();
        std::vector<std::vector<T>> levelOrderTraversal();

    private:
        Node*                       insert(const T& val, Node* node);
        void                        clear(Node* node);
        std::size_t                 getHeight(Node* root) const;
        int                         getBalancingFactor(Node* root);
        Node*                       ll_rotation(Node* node);
        Node*                       rr_rotation(Node* node);
        std::vector<std::vector<T>> levelOrderTraversal(Node* root);

    private:
        Node* m_root;
    };

} // namespace my

#include "AVL_Tree.hpp"

#endif // AVL_TREE_H