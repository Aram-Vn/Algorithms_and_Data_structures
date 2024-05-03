#ifndef BINARY_SEARCH_TREE__HEADERS__BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE__HEADERS__BINARY_SEARCH_TREE_H

#include <functional>
#include <iostream>
#include <memory>
#include <queue>
#include <vector>

namespace my {
    template <typename T>
    class BST
    {
    private:
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
        // Constructors
        BST();
        BST(std::initializer_list<T> init);

        BST(const BST<T>& other);
        BST<T>& operator=(const BST<T>& other);

        BST(BST<T>&& other) noexcept;
        BST<T>& operator=(BST<T>&& other) noexcept;

        ~BST() {}

    public:
        // modifiers
        void insert(const T& value);
        void Delete(const T& val);

        // Traversals
        void                        preTraversal() const;
        void                        inorderTraversal() const;
        void                        postTraversal() const;
        std::vector<std::vector<T>> levelOrderTraversal() const;

        // Queries
        bool        search(const T& value) const;
        const T&    find_min() const;
        const T&    find_max() const;
        std::size_t getHeight() const;
        const T&    getPredecessor(const T& val);
        const T&    getSuccessor(const T& val);

    private:
        // modifiers
        void                  insert(std::unique_ptr<Node>& node, const T& value);
        std::unique_ptr<Node> Delete(const T& val, std::unique_ptr<Node> root);

        // Queries
        Node*       searchNode(Node* root, const T& val);
        bool        search(const std::unique_ptr<Node>& node, const T& value) const;
        Node*       find_min(Node* root) const;
        Node*       find_max(Node* root) const;
        std::size_t getHeight(Node* root) const;
        Node*       getPredecessorHelper(const T& val);
        Node*       getSuccessorHelper(const T& val);

        // Utility functions
        std::unique_ptr<Node> deepCopy(const std::unique_ptr<Node>& node) const;

    private:
        std::unique_ptr<Node> m_root;
    };
} // namespace my

#include "Binary_Search_Tree.hpp"

#endif // BINARY_SEARCH_TREE__HEADERS__BINARY_SEARCH_TREE_H