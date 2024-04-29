#include "../headers/AVL_Tree.h"
#include <functional>
#include <stdexcept>
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

    //-------------------------_move_-----------------------------//
    template <typename T>
    AVL_tree<T>::AVL_tree(AVL_tree<T>&& other)
        : m_root(other.m_root)
    {
        other.m_root = nullptr;
    }

    template <typename T>
    AVL_tree<T>& AVL_tree<T>::operator=(AVL_tree<T>&& other)
    {
        if (this != &other) // Check for self-assignment
        {
            this->clear();
            m_root       = other.m_root;
            other.m_root = nullptr;
        }
        return *this;
    }

    //-------------------------_copy_-----------------------------//
    template <typename T>
    AVL_tree<T>::AVL_tree(const AVL_tree<T>& other)
        : m_root(nullptr)
    {
        m_root = deepCopy(other.m_root);
    }

    template <typename T>
    AVL_tree<T>& AVL_tree<T>::operator=(const AVL_tree<T>& other)
    {
        if (this != &other) // Check for self-assignment
        {
            this->clear();
            m_root = deepCopy(other.m_root);
        }
        return *this;
    }

    template <typename T>
    typename AVL_tree<T>::Node* AVL_tree<T>::deepCopy(typename AVL_tree<T>::Node* node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        Node* newNode = new Node(node->val);

        newNode->left  = deepCopy(node->left);
        newNode->right = deepCopy(node->right);

        return newNode;
    }

    //-------------------------_preOrder_-----------------------------//
    template <typename T>
    void AVL_tree<T>::preOrder() const
    {
        if (m_root == nullptr)
        {
            return;
        }

        std::function<void(Node*)> preorderLambda = [&preorderLambda](Node* root)
        {
            if (root)
            {
                std::cout << root->val << " ";
                preorderLambda(root->left);
                preorderLambda(root->right);
            }
        };

        preorderLambda(m_root);
        std::cout << std::endl;
    }

    //-------------------------_inOrder_-----------------------------//
    template <typename T>
    void AVL_tree<T>::inOrder() const
    {
        if (m_root == nullptr)
        {
            return;
        }

        std::function<void(Node*)> inorderLambda = [&inorderLambda](Node* root)
        {
            if (root)
            {
                inorderLambda(root->left);
                std::cout << root->val << " ";
                inorderLambda(root->right);
            }
        };

        inorderLambda(m_root);
        std::cout << std::endl;
    }

    //-------------------------_postOrder_-----------------------------//
    template <typename T>
    void AVL_tree<T>::postOrder() const
    {
        if (m_root == nullptr)
        {
            return;
        }

        std::function<void(Node*)> postorderLambda = [&postorderLambda](Node* root)
        {
            if (root)
            {
                postorderLambda(root->left);
                postorderLambda(root->right);
                std::cout << root->val << " ";
            }
        };

        postorderLambda(m_root);
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
        else if (val > node->val)
        {
            node->right = insert(val, node->right);
        }
        else
        {
            return node;
        }

        int balanceFactor = getBalancingFactor(node);

        if (balanceFactor > 1 && val < node->left->val) // Left Left Case
        {
            return rr_rotation(node);
        }

        if (balanceFactor < -1 && val > node->right->val) // Right Right Case
        {
            return ll_rotation(node);
        }

        if (balanceFactor > 1 && val > node->left->val) // Left Right Case
        {
            node->left = ll_rotation(node->left);
            return rr_rotation(node);
        }

        if (balanceFactor < -1 && val < node->right->val) // Right Left Case
        {
            node->right = rr_rotation(node->right);
            return ll_rotation(node);
        }

        return node;
    }

    //-------------------------_DeleteNode_-----------------------------//
    template <typename T>
    void AVL_tree<T>::DeleteNode(const T val)
    {
        m_root = DeleteNode(val, m_root);
    }

    template <typename T>
    typename AVL_tree<T>::Node* AVL_tree<T>::DeleteNode(const T& val, Node* node)
    {
        if (node == nullptr)
        {
            return node;
        }

        if (val < node->val)
        {
            node->left = DeleteNode(val, node->left);
        }
        else if (val > node->val)

        {
            node->right = DeleteNode(val, node->right);
        }
        else // Node with the value to be deleted found
        {
            if (node->left == nullptr) // Case 1: Node has no left child
            {
                Node* tmp = node->right;
                delete node;
                return tmp;
            }
            else if (node->right == nullptr) // Case 2: Node has no right child
            {
                Node* tmp = node->left;
                delete node;
                return tmp;
            }
            else // Case 3: Node has both left and right children
            {
                Node* tmp   = findMin(node->right);
                node->val   = tmp->val;
                node->right = DeleteNode(node->val, node->right);
            }
        }

        // Update height and balance factor of the current node
        int balanceFactor = getBalancingFactor(node);

        if (balanceFactor > 1 && getBalancingFactor(node->left) >= 0) // Left Left Case
        {
            return rr_rotation(node);
        }

        if (balanceFactor < -1 && getBalancingFactor(node->right) <= 0) // Right Right Case
        {
            return ll_rotation(node);
        }

        if (balanceFactor > 1 && getBalancingFactor(node->left) < 0) // Left Right Case
        {
            node->left = ll_rotation(node->left);
            return rr_rotation(node);
        }

        if (balanceFactor < -1 && getBalancingFactor(node->right) > 0) // Right Left Case
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

        return getHeight(m_root);
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
                int            Qsize = nodes.size();
                std::vector<T> vec;

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

                    vec.push_back(node->val);
                }

                res.push_back(vec);
            }
        };

        levelOrderLambda(m_root);

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

    //-------------------------_findMin_-----------------------------//
    template <typename T>
    const T& AVL_tree<T>::findMin() const
    {
        if (m_root == nullptr)
        {
            throw std::logic_error("Tree is empty");
        }

        return find_min(m_root)->val;
    }

    template <typename T>
    typename AVL_tree<T>::Node* AVL_tree<T>::findMin(typename AVL_tree<T>::Node* root) const
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        while (root->left != nullptr)
        {
            root = root->left;
        }

        return root;
    }

} // namespace my
