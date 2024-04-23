#include <iostream>
#include <memory>
#include <queue>
#include <vector>

template <class T>
class BST
{
public:
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
    BST();
    BST(std::initializer_list<T> init);

public:
    void insert(const T& value);
    bool search(const T& value) const;

    void preTraversal() const;
    void inorderTraversal() const;
    void postTraversal() const;
    void levelOrderTraversal();

    void        Delete(const T& val);
    const T&    find_min() const;
    const T&    find_max() const;
    std::size_t getHeight() const;
    const T&    getPredecessor(const T& val); 
    const T&    getSuccessor(const T& val);  

private:
    void                        insert(std::unique_ptr<Node>& node, const T& value);
    Node*                       searchNode(Node* root, const T& val);
    void                        preTraversal(const std::unique_ptr<Node>& node) const;
    void                        inorderTraversal(const std::unique_ptr<Node>& node) const;
    void                        postTraversal(const std::unique_ptr<Node>& node) const;
    std::vector<std::vector<T>> levelOrderTraversal(Node* root); //
    bool                        search(const std::unique_ptr<Node>& node, const T& value) const;
    std::unique_ptr<Node>       Delete(const T& val, std::unique_ptr<Node> root);
    Node*                       find_min(Node* root) const;
    Node*                       find_max(Node* root) const;
    std::size_t                 getHeight(Node* root) const;
    Node*                       getPredecessorHelper(const T& val); //
    Node*                       getSuccessorHelper(const T& val);   //

private:
    std::unique_ptr<Node> m_root;
};

#include "Binary_Search_Tree.hpp"
