#ifndef DATA_STRUCTURES_RB_TREE_HEADERS_RB_TREE_H
#define DATA_STRUCTURES_RB_TREE_HEADERS_RB_TREE_H

namespace my {

    template <typename T>
    class RB_Tree
    {
    private:
        struct Node;

    public:
        using value_type      = T;
        using reference       = value_type&;
        using const_reference = const value_type&;
        using pointer         = value_type*;
        using const_pointer   = const pointer;

    private:
        enum class Color
        {
            RED,
            BLACK
        }; // enum class Color

        struct Node
        {
            T     data;
            Node* parent;
            Node* left;
            Node* right;
            Color color = Color::RED;

            Node(const T& val, Color node_color = Color::RED)
                : data(val),
                  parent(nullptr),
                  left(nullptr),
                  right(nullptr),
                  color(node_color)
            {
            }
        };

    public:
        RB_Tree(const T& val);
        ~RB_Tree();
        // functions...

    private:
        // Private helper functions...
        void destroyTree(Node* node);

    private:
        Node* m_root;
        Node* m_nil = new Node(T(), Color::BLACK);
    };

} // namespace my

#include "RB_Tree.hpp"

#endif // DATA_STRUCTURES_RB_TREE_HEADERS_RB_TREE_H