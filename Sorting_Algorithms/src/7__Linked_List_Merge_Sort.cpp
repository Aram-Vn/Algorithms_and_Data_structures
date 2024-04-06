#include "../include/Linked_List_Merge_Sort.h"

Forward_list::Forward_list() : m_head(nullptr)
{
}

Forward_list::Forward_list(std::initializer_list<int> init_list) : m_head(nullptr)
{
    for (auto it = std::rbegin(init_list); it != std::rend(init_list); ++it)

    {
        this->push(*it);
    }
}

Forward_list ::~Forward_list()
{
    while (m_head)
    {
        Node* temp = m_head;
        m_head = m_head->next;
        delete temp;
    }
}

void Forward_list::push(int new_data)
{
    Node* new_node = new Node(new_data);
    if (m_head == nullptr)
    {
        m_head = new_node;
    }
    else
    {
        new_node->next = m_head;
        m_head = new_node;
    }
}

void Forward_list::print()
{
    Node* current = m_head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void Forward_list::MergeSort()
{
    MergeSorthelper(m_head);
}

Forward_list::Node* Forward_list::SortedMerge(Node* first, Node* second)
{
    Node* result = nullptr;

    if (first == nullptr)
    {
        return second;
    }
    else if (second == nullptr)
    {
        return first;
    }

    if (first->data <= second->data)
    {
        result = first;
        result->next = SortedMerge(first->next, second);
    }
    else
    {
        result = second;
        result->next = SortedMerge(first, second->next);
    }

    return result;
}

void Forward_list::splitList(Node* source, Node*& firstRef, Node*& secondRef)
{
    Node* slow = source;
    Node* fast = source->next;

    while (fast != nullptr)
    {
        fast = fast->next;

        if (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    firstRef = source;
    secondRef = slow->next;
    slow->next = nullptr;
}

void Forward_list::MergeSorthelper(Node*& head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    Node* firstHalf;
    Node* secondHalf;
    splitList(head, firstHalf, secondHalf);

    MergeSorthelper(firstHalf);
    MergeSorthelper(secondHalf);

    head = SortedMerge(firstHalf, secondHalf);
}