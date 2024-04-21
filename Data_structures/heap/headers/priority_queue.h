#ifndef THEAP_H
#define THEAP_H

#include <cstddef>
#include <functional>
#include <iostream>
#include <vector>

namespace my {
    template <typename T, typename Compare = std::less<T>>
    class priority_queue
    {
        using value_compare   = Compare;
        using value_type      = T;
        using size_type       = size_t;
        using const_reference = const T&;
        using container_type  = std::vector<value_type>;

    public:
        ~priority_queue() {}
        priority_queue();
        priority_queue(container_type& input);

        template <typename RandomAccessIterator>
        priority_queue(RandomAccessIterator first, RandomAccessIterator last); // gets std::vector iterators

    public:
        void            push(const_reference val); // Insert a value into the priority queue
        void            pop();                     // Remove the top element from the priority queue
        const_reference top();                     // Get the top element of the priority queue
        bool            empty();                   // Check if the priority queue is empty
        size_type       size();                    // Get the number of elements in the priority queue
        void            print();                   // Print the elements of the priority queue

    private:
        size_t parent(size_t ind);       // returns parent index
        size_t left(size_t ind);         // returns ind-s left node index
        size_t right(size_t ind);        // returns ind-s right node index
        void   make_heap();              // Build a heap from the elements
        void   heapify_down(size_t ind); // Heapify down the element at given index

    private:
        container_type m_heap; // The vector representing the heap
        size_type      m_size; // The size of the priority queue
        value_compare  m_cmp;  // The comparison function for comparing elements
    };

#include "../src/priority_queue.hpp"

} // namespace my

#endif // THEAP_H