template <typename T>
BST<T>::BST()
    : m_root(nullptr)
{
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

    if (val < root->val)
    {
        root->left = Delete(val, std::move(root->left));
    }
    else if (val > root->val)
    {
        root->right = Delete(val, std::move(root->right));
    }
    else
    {
        if (!root->left)
        {
            return std::move(root->right);
        }
        else if (!root->right)
        {
            return std::move(root->left);
        }
        else
        {
            Node* tmp   = find_min(root->right.get());
            root->val   = tmp->val;
            root->right = Delete(root->val, std::move(root->right));
        }
    }

    return std::move(root);
}
