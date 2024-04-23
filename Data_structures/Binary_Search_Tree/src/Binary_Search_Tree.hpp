// #include "../headers/Binary_Search_Tree.h"

template <typename T>
BST<T>::BST()
    : m_root(nullptr)
{
}

template <typename T>
BST<T>::BST(std::initializer_list<T> init)
    : m_root(nullptr)
{
    for (const auto& elem : init)
    {
        this->insert(elem);
    }
}

//-------------------------_insert_-----------------------------//
template <typename T>
void BST<T>::insert(const T& value)
{
    insert(m_root, value);
}

template <typename T>
void BST<T>::insert(std::unique_ptr<Node>& node, const T& value)
{
    if (!node)
    {
        node = std::make_unique<Node>(value);
    }
    else
    {
        if (value < node->val)
        {
            insert(node->left, value);
        }
        else
        {
            insert(node->right, value);
        }
    }
}

//-------------------------_preTraversal_-----------------------------//
template <typename T>
void BST<T>::preTraversal() const
{
    preTraversal(m_root);
    std::cout << std::endl;
}

template <typename T>
void BST<T>::preTraversal(const std::unique_ptr<Node>& node) const
{
    if (node)
    {
        std::cout << node->val << " ";
        preTraversal(node->left);
        preTraversal(node->right);
    }
}

//-------------------------_inorderTraversal_-----------------------------//
template <typename T>
void BST<T>::inorderTraversal() const
{
    inorderTraversal(m_root);
    std::cout << std::endl;
}

template <typename T>
void BST<T>::inorderTraversal(const std::unique_ptr<Node>& node) const
{
    if (node)
    {
        inorderTraversal(node->left);
        std::cout << node->val << " ";
        inorderTraversal(node->right);
    }
}

//-------------------------_postTraversal_-----------------------------//
template <typename T>
void BST<T>::postTraversal() const
{
    postTraversal(m_root);
    std::cout << std::endl;
}

template <typename T>
void BST<T>::postTraversal(const std::unique_ptr<Node>& node) const
{
    if (node)
    {
        postTraversal(node->left);
        postTraversal(node->right);
        std::cout << node->val << " ";
    }
}

//-------------------------_levelOrderTraversal_-----------------------------//
template <typename T>
void BST<T>::levelOrderTraversal()
{
    std::vector<std::vector<T>> res;
    res = levelOrderTraversal(m_root.get());

    for (auto& elem : res)
    {
        for (auto& val : elem)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

template <typename T>
std::vector<std::vector<T>> BST<T>::levelOrderTraversal(typename BST<T>::Node* root)
{
    std::vector<std::vector<int>> res;

    if (root == nullptr)
    {
        return res;
    }

    std::queue<Node*> nodes;
    nodes.push(root);

    while (!nodes.empty())
    {
        int              Qsize = nodes.size();
        std::vector<int> vec;

        for (int i = 0; i < Qsize; ++i)
        {
            Node* node = nodes.front();
            nodes.pop();

            if (node->left != nullptr)
            {
                nodes.push(node->left.get());
            }

            if (node->right != nullptr)
            {
                nodes.push(node->right.get());
            }

            vec.push_back(node->val);
        }

        res.push_back(vec);
    }
    return res;
}

//-------------------------_search_-----------------------------//
template <typename T>
bool BST<T>::search(const T& value) const
{
    return search(m_root, value);
}

template <typename T>
bool BST<T>::search(const std::unique_ptr<Node>& node, const T& value) const
{
    if (!node)
    {
        return false;
    }

    if (node->val == value)
    {
        return true;
    }
    else if (value < node->val)
    {
        return search(node->left, value);
    }
    else
    {
        return search(node->right, value);
    }
}

//--------------------------_search_node_---------------------//
template <typename T>
typename BST<T>::Node* BST<T>::searchNode(typename BST<T>::Node* root, const T& val)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->val == val)
    {
        return root;
    }

    if (root->val < val)
    {
        return searchNode(root->right.get(), val);
    }

    return searchNode(root->left.get(), val);
}

//-------------------------_find_min_-----------------------------//
template <typename T>
const T& BST<T>::find_min() const
{
    if (m_root == nullptr)
    {
        throw std::logic_error("Tree is empty");
    }

    return find_min(m_root.get())->val;
}

template <class T>
typename BST<T>::Node* BST<T>::find_min(typename BST<T>::Node* root) const
{
    if (root == nullptr)
    {
        return nullptr;
    }

    while (root->left != nullptr)
    {
        root = root->left.get();
    }

    return root;
}

//-------------------------_find_max_-----------------------------//
template <typename T>
const T& BST<T>::find_max() const
{
    if (m_root == nullptr)
    {
        throw std::logic_error("Tree is empty");
    }

    return find_max(m_root.get())->val;
}

template <typename T>
typename BST<T>::Node* BST<T>::find_max(Node* root) const
{
    if (root == nullptr)
    {
        return nullptr;
    }

    while (root->right != nullptr)
    {
        root = root->right.get();
    }

    return root;
}

//-------------------------_getHeight_-----------------------------//
template <typename T>
std::size_t BST<T>::getHeight() const
{
    if (m_root == nullptr)
    {
        throw std::logic_error("Tree is empty");
    }

    return getHeight(m_root.get());
}

template <typename T>
std::size_t BST<T>::getHeight(Node* root) const
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        std::size_t leftH  = getHeight(root->left.get());
        std::size_t rightH = getHeight(root->right.get());

        return std::max(leftH, rightH) + 1;
    }
}
//-------------------------_delete_-----------------------------//
template <typename T>
void BST<T>::Delete(const T& val)
{
    m_root = Delete(val, std::move(m_root));
}

template <typename T>
std::unique_ptr<typename BST<T>::Node> BST<T>::Delete(const T& val, std::unique_ptr<Node> root)
{
    if (!root)
    {
        return nullptr;
    }

    if (val < root->val) // If the value is less than the current node's value, delete from the left subtree
    {
        root->left = Delete(val, std::move(root->left));
    }
    else if (val > root->val) // If the value is greater than the current node's value, delete from the right subtree
    {
        root->right = Delete(val, std::move(root->right));
    }
    else // Node with the value to be deleted found
    {
        if (root->left == nullptr) // Case 1: Node has no left child
        {
            return std::move(root->right);
        }
        else if (root->right == nullptr) // Case 2: Node has no right child
        {
            return std::move(root->left);
        }
        else // Case 3: Node has both left and right children
        {
            Node* tmp   = find_min(root->right.get());
            root->val   = tmp->val;
            root->right = Delete(root->val, std::move(root->right));
        }
    }

    return std::move(root);
}

//-------------------------_successor_-----------------------------//
template <typename T>
const T& BST<T>::getSuccessor(const T& val)
{
    return getSuccessorHelper(val)->val;
}

template <typename T>
typename BST<T>::Node* BST<T>::getSuccessorHelper(const T& val)
{
    /*
     * Successor of a node in a Binary Search Tree (BST) is defined as
     * the node with the smallest value greater than the value of the given
     * node.
     */

    Node* tar = searchNode(m_root.get(), val);

    if (tar == nullptr)
    {
        return nullptr;
    }

    if (tar->right != nullptr)
    {
        return this->find_min(tar->right.get());
    }

    /*
     * ancestors is any other node on the path from the node to the root.
     */

    Node* successor = nullptr;
    Node* ancestor  = m_root.get();

    while (ancestor != tar)
    {
        if (val < ancestor->val)
        {
            successor = ancestor;
            ancestor  = ancestor->left.get();
        }
        else
        {
            ancestor = ancestor->right.get();
        }
    }

    return successor;
}

//-------------------------_predecessor_-----------------------------//
template <typename T>
const T& BST<T>::getPredecessor(const T& val)
{
    return getPredecessorHelper(val)->val;
}

template <typename T>
typename BST<T>::Node* BST<T>::getPredecessorHelper(const T& val)
{
    /*
     * Predecessor of a node in a Binary Search Tree (BST) is defined as
     * the node with the largest value smaller than the value of the given node.
     */

    Node* tar = searchNode(m_root.get(), val);

    if (tar == nullptr)
    {
        return nullptr;
    }

    if (tar->left != nullptr)
    {
        return find_max(tar->left.get());
    }

    /*
     * ancestors is any other node on the path from the node to the root.
     */

    Node* predecessor = nullptr;
    Node* ancestor    = m_root.get();

    while (ancestor != tar)
    {
        if (val < ancestor->val)
        {
            ancestor = ancestor->left.get();
        }
        else
        {
            predecessor = ancestor;
            ancestor    = ancestor->right.get();
        }
    }

    return predecessor;
}