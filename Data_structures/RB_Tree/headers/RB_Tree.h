#ifndef DATA_STRUCTURES_RB_TREE_HEADERS_RB_TREE_H
#define DATA_STRUCTURES_RB_TREE_HEADERS_RB_TREE_H

#include <initializer_list>

namespace my {

    template <typename T>
    class RB_Tree
    {
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
            value_type data;
            Node*      parent;
            Node*      left;
            Node*      right;
            Color      color = Color::RED;

            Node(const_reference val, Node* node = nullptr, Color node_color = Color::RED)
                : data(val),
                  parent(node),
                  left(node),
                  right(node),
                  color(node_color)
            {
            }
        }; // struct Node

    public:
        RB_Tree();                    //
        RB_Tree(const_reference val); //
        RB_Tree(std::initializer_list<value_type>);
        ~RB_Tree();
        // functions...

    private:
        // modifiers
        void  destroyTree(Node* node);
        Node* left_rotate(Node* node); // ?
        Node* right_rotate(Node* node);

    private:
        Node* m_root;
        Node* m_nil = new Node(value_type{}, nullptr, Color::BLACK);
    }; // class RB_Tree

} // namespace my

#include "RB_Tree.hpp"

#endif // DATA_STRUCTURES_RB_TREE_HEADERS_RB_TREE_H