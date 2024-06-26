#ifndef DATA_STRUCTURES_RB_TREE_HEADERS_RB_TREE_H
#define DATA_STRUCTURES_RB_TREE_HEADERS_RB_TREE_H

#include <cstdint>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <queue>

#ifdef TESTING_ENABLED
    #define VISIBILITY(cond) public:
#else
    #define VISIBILITY(cond) private:
#endif

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
        enum class Color : std::uint8_t
        {
            RED,
            BLACK
        }; // enum class Color

        struct Node
        {
            value_type val;
            Node*      parent;
            Node*      left;
            Node*      right;
            Color      color = Color::RED;

            Node(const_reference new_val, Node* node = nullptr, Color node_color = Color::RED)
                : val(new_val),
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
        RB_Tree(std::initializer_list<value_type> init_list);
        ~RB_Tree() noexcept; //

        void                                                inorder_traversal();     //
        std::vector<std::vector<std::pair<std::string, T>>> level_order_traversal(); //

        void            clearTree();                 //
        void            insert(const_reference val); //
        void            delete_val(const_reference val);
        const_reference get_minVal() const;
        bool            check_black_height() const;
        bool            check_no_adjacent_red_nodes() const;
        void            display();

    VISIBILITY(TESTING_ENABLED)
        void  destroy_tree(Node* node); //
        void  insert(Node* z_node);     //
        void  insert_fixup(Node* z_node);
        Node* left_rotate(Node* x_node);  //
        Node* right_rotate(Node* y_node); //
        void  delete_node(Node* z_node);
        void  delete_fixup(Node* x_node);
        void  transplant(Node* u_node, Node* v_node); //
        Node* get_minNode(Node* node) const;
        Node* find_node(const_reference val);
        bool  root_color() const;

        // for testing
        bool  check_black_height(Node* node) const;
        bool  check_no_adjacent_red_nodes(Node* node) const;

    VISIBILITY(TESTING_ENABLED)
        Node* m_root;
        Node* m_nil = new Node(value_type{}, nullptr, Color::BLACK);
    }; // class RB_Tree

} // namespace my

#include "../src/RB_Tree.hpp"

#endif // DATA_STRUCTURES_RB_TREE_HEADERS_RB_TREE_H