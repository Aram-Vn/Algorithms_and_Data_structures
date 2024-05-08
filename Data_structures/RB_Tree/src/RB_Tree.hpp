#include "RB_Tree.h"
#include <functional>
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
            m_root = new Node(val, m_nil, Color::BLACK);
        }
    }

    template <typename T>
    RB_Tree<T>::RB_Tree(std::initializer_list<RB_Tree<T>::value_type> init_list)
        : m_root(nullptr)
    {
        for (const auto& elem : init_list)
        {
            this->insert(elem);
        }
    }

    template <typename T>
    RB_Tree<T>::~RB_Tree() noexcept
    {
        if (m_root != nullptr)
        {
            this->destroy_tree(m_root);
        }

        delete m_nil;
    }

    //-------------------------_-destroyTree-_-----------------------------//
    template <typename T>
    void RB_Tree<T>::clearTree()
    {
        this->destroyTree(m_root);
        m_root = nullptr;
    }

    template <typename T>
    void RB_Tree<T>::destroy_tree(Node* node)
    {
        if (node != m_nil)
        {
            this->destroy_tree(node->left);
            this->destroy_tree(node->right);
            delete node;
        }
    }

    //-------------------------_-insert-_-----------------------------//
    template <typename T>
    void RB_Tree<T>::insert(RB_Tree<T>::const_reference val)
    {
        if (m_root == nullptr)
        {
            m_root = new Node(val, m_nil, Color::BLACK);
            return;
        }

        Node* z_node = new Node(val, m_nil);
        this->insert(z_node);
    }

    template <typename T>
    void RB_Tree<T>::insert(Node* z_node)
    {
        Node* y_node = m_nil;
        Node* x_node = m_root;

        while (x_node != m_nil)
        {
            y_node = x_node;
            if (z_node->val < x_node->val)
            {
                x_node = x_node->left;
            }
            else if (z_node->val > x_node->val)
            {
                x_node = x_node->right;
            }
            else // node  already exists
            {
                delete z_node;
                return;
            }
        }
        z_node->parent = y_node;

        if (y_node == m_nil)
        {
            m_root = z_node;
        }
        else if (z_node->val < y_node->val)
        {
            y_node->left = z_node;
        }
        else
        {
            y_node->right = z_node;
        }

        this->insert_fixup(z_node);
    }

    //-------------------------_-insert_fixup-_-----------------------------//
    template <typename T>
    void RB_Tree<T>::insert_fixup(Node* z_node)
    {
        while (z_node->parent->color == Color::RED)
        {
            if (z_node->parent == z_node->parent->parent->left)
            {
                Node* y_node = z_node->parent->parent->right; // uncle

                if (y_node->color == Color::RED) // Case 1: uncle is red
                {
                    z_node->parent->color         = Color::BLACK;
                    y_node->color                 = Color::BLACK;
                    z_node->parent->parent->color = Color::RED;
                    z_node                        = z_node->parent->parent;
                }
                else // Case 2: uncle is black
                {
                    if (z_node == z_node->parent->right) // Case 2a: z_node is a right child
                    {
                        z_node = z_node->parent;
                        this->left_rotate(z_node);
                    }
                    else // Case 2b: z_node is a left child
                    {
                        z_node->parent->color         = Color::BLACK;
                        z_node->parent->parent->color = Color::RED;
                        this->right_rotate(z_node->parent->parent);
                    }
                }
            }
            else // Mirror cases for right child of grandparent
            {
                Node* y_node = z_node->parent->parent->left; // uncle

                if (y_node->color == Color::RED) // Case 1: uncle is red
                {
                    z_node->parent->color         = Color::BLACK;
                    y_node->color                 = Color::BLACK;
                    z_node->parent->parent->color = Color::RED;
                    z_node                        = z_node->parent->parent;
                }
                else // Case 2: uncle is black
                {
                    if (z_node == z_node->parent->left) // Case 2a: z_node is a left child
                    {
                        z_node = z_node->parent;
                        this->right_rotate(z_node);
                    }
                    else // Case 2b: z_node is a right child
                    {
                        z_node->parent->color         = Color::BLACK;
                        z_node->parent->parent->color = Color::RED;
                        this->left_rotate(z_node->parent->parent);
                    }
                }
            }
        }

        m_root->color = Color::BLACK;
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

    //-------------------------_-right_rotate-_-----------------------------//
    template <typename T>
    typename RB_Tree<T>::Node* RB_Tree<T>::right_rotate(Node* y_node)
    {
        Node* x_node = y_node->left; // Set x_node

        // Turn x_node's right subtree into y_node's left subtree
        y_node->left = x_node->right;
        if (x_node->right != m_nil)
        {
            x_node->right->parent = y_node;
        }

        // Link y_node's parent to x_node
        x_node->parent = y_node->parent;
        if (y_node->parent == m_nil)
        {
            m_root = x_node;
        }
        else if (y_node == y_node->parent->right)
        {
            y_node->parent->right = x_node;
        }
        else
        {
            y_node->parent->left = x_node;
        }

        // Put y_node on x_node's right
        x_node->right  = y_node;
        y_node->parent = x_node;

        return x_node;
    }

    //-------------------------_-delete_node-_-----------------------------//
    template <typename T>
    void RB_Tree<T>::delete_val(RB_Tree<T>::const_reference val)
    {
        Node* node_to_delete = find_node(val);

        if (node_to_delete == nullptr)
        {
            throw std::out_of_range("Value to be deleted does not exist in the tree.");
        }

        this->delete_node(node_to_delete);
    }

    template <typename T>
    void RB_Tree<T>::delete_node(Node* z_node)
    {
        if (z_node == nullptr || z_node == m_nil)
        {
            return;
        }

        Node* y_node           = z_node;
        Node* x_node           = nullptr;
        Color y_original_color = y_node->color;

        if (z_node->left == m_nil)
        {
            x_node = z_node->right;
            transplant(z_node, z_node->right);
        }
        else if (z_node->right == m_nil)
        {
            x_node = z_node->left;
            transplant(z_node, z_node->left);
        }
        else
        {
            y_node           = get_minNode(z_node->right);
            y_original_color = y_node->color;
            x_node           = y_node->right;
            if (y_node->parent == z_node)
            {
                x_node->parent = y_node;
            }
            else
            {
                transplant(y_node, y_node->right);
                y_node->right         = z_node->right;
                y_node->right->parent = y_node;
            }
            transplant(z_node, y_node);
            y_node->left         = z_node->left;
            y_node->left->parent = y_node;
            y_node->color        = z_node->color;
        }

        delete z_node;

        if (y_original_color == Color::BLACK)
        {
            delete_fixup(x_node);
        }
    }

    //-------------------------_-delete_fixup-_-----------------------------//
    template <typename T>
    void RB_Tree<T>::delete_fixup(Node* x_node)
    {
        while (x_node != m_root && x_node->color == Color::BLACK)
        {
            if (x_node == x_node->parent->left)
            {
                Node* w_sibling = x_node->parent->right;

                if (w_sibling->color == Color::RED) // Case 1: x_node's sibling is red
                {
                    w_sibling->color      = Color::BLACK;
                    x_node->parent->color = Color::RED;
                    left_rotate(x_node->parent);
                    w_sibling = x_node->parent->right;
                }

                // Case 2: x_node's sibling is black and both of w_node's children are black
                if (w_sibling->left->color == Color::BLACK && w_sibling->right->color == Color::BLACK)
                {
                    w_sibling->color = Color::RED;
                    x_node           = x_node->parent;
                }
                else
                {
                    // Case 3: x_node's sibling is black, w_node's left child is red, and right child is black
                    if (w_sibling->right->color == Color::BLACK)
                    {
                        w_sibling->left->color = Color::BLACK;
                        w_sibling->color       = Color::RED;
                        right_rotate(w_sibling);
                        w_sibling = x_node->parent->right;
                    }

                    // Case 4: x_node's sibling is black, and w_node's right child is red
                    w_sibling->color        = x_node->parent->color;
                    x_node->parent->color   = Color::BLACK;
                    w_sibling->right->color = Color::BLACK;
                    left_rotate(x_node->parent);
                    x_node = m_root;
                }
            }
            else // miror case
            {
                Node* w_sibling = x_node->parent->left;

                if (w_sibling->color == Color::RED)
                {
                    w_sibling->color      = Color::BLACK;
                    x_node->parent->color = Color::RED;
                    right_rotate(x_node->parent);
                    w_sibling = x_node->parent->left;
                }

                if (w_sibling->right->color == Color::BLACK && w_sibling->left->color == Color::BLACK)
                {
                    w_sibling->color = Color::RED;
                    x_node           = x_node->parent;
                }
                else
                {
                    if (w_sibling->left->color == Color::BLACK)
                    {
                        w_sibling->right->color = Color::BLACK;
                        w_sibling->color        = Color::RED;
                        left_rotate(w_sibling);
                        w_sibling = x_node->parent->left;
                    }

                    w_sibling->color       = x_node->parent->color;
                    x_node->parent->color  = Color::BLACK;
                    w_sibling->left->color = Color::BLACK;
                    right_rotate(x_node->parent);
                    x_node = m_root;
                }
            }
        }

        x_node->color = Color::BLACK;
    }

    //-------------------------_-transplant-_-----------------------------//
    template <typename T>
    void RB_Tree<T>::transplant(Node* U_node, Node* V_node)
    {
        if (U_node->parent == m_nil)
        {
            m_root = V_node;
        }

        if (U_node == U_node->parent->left)
        {
            U_node->parent->left = V_node;
        }
        else
        {
            U_node->parent->right = V_node;
        }

        V_node->parent = U_node->parent;
    }

    //-------------------------_-get_min-_-----------------------------//
    template <typename T>
    typename RB_Tree<T>::const_reference RB_Tree<T>::get_minVal() const
    {
        return get_minNode(m_root)->val;
    }

    template <typename T>
    typename RB_Tree<T>::Node* RB_Tree<T>::get_minNode(Node* node) const
    {
        if (node == m_nil)
        {
            return nullptr;
        }

        while (node->left != m_nil)
        {
            node = node->left;
        }

        return node;
    }

    //-------------------------_-find_node-_-----------------------------//
    template <typename T>
    typename RB_Tree<T>::Node* RB_Tree<T>::find_node(RB_Tree<T>::const_reference val)
    {
        Node* node = m_root;

        while (node != m_nil)
        {
            if (node->val > val)
            {
                node = node->left;
            }
            else if (node->val < val)
            {
                node = node->right;
            }
            else
            {
                return node;
            }
        }

        return nullptr;
    }

    //-------------------------_-inorder_traversal-_-----------------------------//
    template <typename T>
    void RB_Tree<T>::inorder_traversal()
    {
        if (m_root == nullptr)
        {
            std::cout << "tree is empty" << std::endl;
            return;
        }

        std::function<void(Node*)> inorder_lambda = [this, &inorder_lambda](Node* node)
        {
            if (node != m_nil)
            {
                inorder_lambda(node->left);
                std::cout << (node->color == Color::RED ? "RED" : "BLACK") << ": " << node->val << " ,";
                inorder_lambda(node->right);
            }
        };

        inorder_lambda(m_root);
        std::cout << std::endl;
    }

    //-------------------------level_order_traversal-----------------------------//
    template <typename T>
    std::vector<std::vector<std::pair<std::string, T>>> RB_Tree<T>::level_order_traversal()
    {
        std::vector<std::vector<std::pair<std::string, RB_Tree<T>::value_type>>> res;

        auto levelOrderLambda = [&res](Node* root) -> void
        {
            if (root == nullptr)
            {
                return;
            }

            std::queue<Node*> nodes;
            nodes.push(root);

            while (!nodes.empty())
            {
                size_t                                                      Qsize = nodes.size();
                std::vector<std::pair<std::string, RB_Tree<T>::value_type>> vec;

                for (size_t i = 0; i < Qsize; ++i)
                {
                    Node* node = nodes.front();
                    nodes.pop();

                    if (node->left != nullptr)
                    {
                        nodes.push(node->left);
                    }

                    if (node->right != nullptr)
                    {
                        nodes.push(node->right);
                    }

                    if (node->right == nullptr && node->right == nullptr)
                    {
                        vec.push_back({ "Nil", node->val });
                    }
                    else
                    {
                        vec.push_back({ (node->color == Color::RED ? "RED" : "BLACK"), node->val });
                    }
                }

                res.push_back(vec);
            }
        };

        levelOrderLambda(m_root);

        for (const auto& level : res)
        {
            for (const auto& node : level)
            {
                std::cout << node.first << ": " << node.second << ", ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        return res;
    }

    template <typename T>
    bool RB_Tree<T>::check_black_height(Node* node) const
    {
        int left_black_height = 0, right_black_height = 0;

        if (node == m_nil)
        {
            return true;
        }

        left_black_height  = check_black_height(node->left);
        right_black_height = check_black_height(node->right);

        if (left_black_height != right_black_height)
        {
            return false;
        }

        return (node->color == Color::BLACK) ? left_black_height + 1 : left_black_height;
    }

    template <typename T>
    bool RB_Tree<T>::check_black_height() const
    {
        return check_black_height(m_root);
    }

    template <typename T>
    bool RB_Tree<T>::root_color() const
    {
        return m_root->color == Color::BLACK;
    }

    template <typename T>
    bool RB_Tree<T>::check_no_adjacent_red_nodes(Node* node) const
    {
        if (node == m_nil)
            return true;

        if (!check_no_adjacent_red_nodes(node->left))
            return false;

        if (node->color == Color::RED && node->left->color == Color::RED)
            return false;

        return check_no_adjacent_red_nodes(node->right);
    }

    template <typename T>
    bool RB_Tree<T>::check_no_adjacent_red_nodes() const
    {
        return check_no_adjacent_red_nodes(m_root);
    }

    template <typename T>
    void RB_Tree<T>::display()
    {
        std::function<void(Node*, int)> displayLambda = [&displayLambda, this](Node* node, int dept)
        {
            if (node == m_nil || node == nullptr)
            {
                return;
            }

            displayLambda(node->right, dept + 4);

            std::cout << std::setw(dept) << (node->color == Color::BLACK ? "B:" : "R:") << node->val << std::endl;

            displayLambda(node->left, dept + 4);
        };

        displayLambda(m_root, 0);
        std::cout << std::endl;
    }

} // namespace my
