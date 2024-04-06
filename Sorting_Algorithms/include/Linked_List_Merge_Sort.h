#ifndef LINKED_LIST_MERGE_SORT_H
#define LINKED_LIST_MERGE_SORT_H

#include <initializer_list>
#include <iostream>

class Forward_list
{
public:
    struct Node
    {
        int data;
        Node(int x) : data(x), next(nullptr) {}
        Node* next;
    };
    Node* m_head;

public:
    Forward_list();
    Forward_list(std::initializer_list<int> init_list);
    ~Forward_list();

public:
    void push(int new_data);
    void print();
    void MergeSort();

private:
    Node* SortedMerge(Node* first, Node* second);
    void splitList(Node* source, Node*& firstRef, Node*& secondRef);
    void MergeSorthelper(Node*& head);
};

#endif // LINKED_LIST_MERGE_SORT_H