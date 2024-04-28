// #include "../headers/AVL_Tree.h"

#include <functional>
namespace my {
    template <typename T>
    AVL_tree<T>::AVL_tree()
        : m_root(nullptr)
    {
    }

    template <typename T>
    AVL_tree<T>::AVL_tree(std::initializer_list<T> init_list)
        : m_root(nullptr)
    {
        for (const auto& elem : init_list)
        {
            this->insert(elem);
        }
    }

    template <typename T>
    AVL_tree<T>::~AVL_tree<T>()
    {
        clear(m_root);
    }

    template <typename T>
    void AVL_tree<T>::print()
    {
        if (m_root == nullptr)
        {
            return;
        }

        std::function<void(Node*)> recv = [&recv](Node* root)
        {
            if (root->left)
            {
                recv(root->left);
            }

            std::cout << root->val << " ";

            if (root->right)
            {
                recv(root->right);
            }
        };

        recv(m_root);
        std::cout << std::endl;
    }

    //-------------------------_insert_-----------------------------//
    template <typename T>
    void AVL_tree<T>::insert(const T& val)
    {
        m_root = insert(val, m_root);
    }

    template <typename T>
    typename AVL_tree<T>::Node* AVL_tree<T>::insert(const T& val, typename AVL_tree<T>::Node* node)
    {
        if (!node)
        {
            return new Node(val);
        }

        if (val < node->val)
        {
            node->left = insert(val, node->left);
        }
        else
        {
            node->right = insert(val, node->right);
        }

        int balanceFactor = getBalancingFactor(node);

        // Left Left Case
        if (balanceFactor > 1 && val < node->left->val)
        {
            return rr_rotation(node);
        }
        // Right Right Case
        if (balanceFactor < -1 && val > node->right->val)
        {
            return ll_rotation(node);
        }
        // Left Right Case
        if (balanceFactor > 1 && val > node->left->val)
        {
            node->left = ll_rotation(node->left);
            return rr_rotation(node);
        }
        // Right Left Case
        if (balanceFactor < -1 && val < node->right->val)
        {
            node->right = rr_rotation(node->right);
            return ll_rotation(node);
        }

        return node;
    }

    //-------------------------_get_balancing_factor_-----------------------------//
    template <typename T>
    int AVL_tree<T>::getBalancingFactor(typename AVL_tree<T>::Node* root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        return (getHeight(root->left) - getHeight(root->right));
    }

    //-------------------------_getHeight_-----------------------------//
    template <typename T>
    std::size_t AVL_tree<T>::getHeight() const
    {
        if (m_root == nullptr)
        {
            std::cout << "Tree is empty\n";
        }

        return getHeightm_root;
    }

    template <typename T>
    std::size_t AVL_tree<T>::getHeight(Node* root) const
    {
        if (root == nullptr)
        {
            return 0;
        }
        else
        {
            std::size_t leftH  = getHeight(root->left);
            std::size_t rightH = getHeight(root->right);

            return std::max(leftH, rightH) + 1;
        }
    }

    //-------------------------_ll_rotation_-----------------------------//
    template <typename T>
    typename AVL_tree<T>::Node* AVL_tree<T>::ll_rotation(typename AVL_tree<T>::Node* node)
    {
        Node* tmp_root = node->right;
        node->right    = tmp_root->left;
        tmp_root->left = node;
        return tmp_root;
    }

    //-------------------------_rr_rotation_-----------------------------//
    template <typename T>
    typename AVL_tree<T>::Node* AVL_tree<T>::rr_rotation(typename AVL_tree<T>::Node* node)
    {
        Node* tmp_root  = node->left;
        node->left      = tmp_root->right;
        tmp_root->right = node;
        return tmp_root;
    }

    //-------------------------_clear_-----------------------------//
    template <typename T>
    void AVL_tree<T>::clear()
    {
        clear(m_root);
    }

    template <typename T>
    void AVL_tree<T>::clear(Node* root)
    {
        if (root != nullptr)
        {
            clear(root->left);
            clear(root->right);

            delete root;
        }

        m_root = nullptr;
    }

    //-------------------------_levelOrderTraversal_-----------------------------//
    template <typename T>
    std::vector<std::vector<T>> AVL_tree<T>::levelOrderTraversal()
    {
        std::vector<std::vector<T>> res;
        res = levelOrderTraversal(m_root);

        for (auto& elem : res)
        {
            for (auto& val : elem)
            {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        return res;
    }

    template <typename T>
    std::vector<std::vector<T>> AVL_tree<T>::levelOrderTraversal(typename AVL_tree<T>::Node* root)
    {
        std::vector<std::vector<T>> res;

        if (root == nullptr)
        {
            return res;
        }

        std::queue<Node*> nodes;
        nodes.push(root);

        while (!nodes.empty())
        {
            int            Qsize = nodes.size();
            std::vector<T> vec; // Use T instead of int

            for (int i = 0; i < Qsize; ++i)
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

                vec.push_back(node->val); // Access val directly
            }

            res.push_back(vec);
        }
        return res;
    }

} // namespace my
