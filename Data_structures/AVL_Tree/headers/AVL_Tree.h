#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <functional>
#include <initializer_list>
#include <iostream>
#include <queue>
#include <stdexcept>
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
        // Constructors and destructor
        AVL_tree();
        AVL_tree(std::initializer_list<T> init_list);
        ~AVL_tree();

        // Copy constructor and copy assignment operator
        AVL_tree(const AVL_tree<T>& other);
        AVL_tree<T>& operator=(const AVL_tree<T>& other);

        // Move constructor and move assignment operator
        AVL_tree(AVL_tree<T>&& other) noexcept;
        AVL_tree<T>& operator=(AVL_tree<T>&& other) noexcept;

    public: // modifiers
        void insert(const T& val);
        void DeleteNode(const T val);
        void clear();

    public: // Queries
        std::size_t getHeight() const;
        const T&    findMin() const;
        const T&    findMax() const;

    public: // Traversals
        void                        preOrder() const;
        void                        inOrder() const;
        void                        postOrder() const;
        std::vector<std::vector<T>> levelOrderTraversal() const;

    private:
        // modifiers
        Node* insert(const T& val, Node* node);
        Node* DeleteNode(const T& val, Node* node);
        void  clear(Node* node);
        Node* ll_rotation(Node* node);
        Node* rr_rotation(Node* node);
        Node* deepCopy(Node* node);

        // Queries
        std::size_t getHeight(Node* root) const;
        int         getBalancingFactor(Node* root) const;
        Node*       findMin(Node* root) const;
        Node*       findMax(Node* root) const;

    private:
        Node* m_root;
    };

} // namespace my

#include "AVL_Tree.hpp"

#endif // AVL_TREE_H