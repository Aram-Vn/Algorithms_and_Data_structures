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
        void                      push(const_reference val);    // Insert a value into the priority queue
        void                      pop();                        // Remove the top element from the priority queue
        constexpr const_reference top() const;                  // Get the top element of the priority queue
        constexpr bool            empty() const noexcept;       // Check if the priority queue is empty
        constexpr size_type       size() const noexcept;        // Get the number of elements in the priority queue
        void                      print() const noexcept;       // Print the elements of the priority queue
        void                      print_level() const noexcept; // Print the elements of the priority queue by level

    private:
        constexpr size_t parent(size_t ind) const noexcept; // returns parent index
        constexpr size_t left(size_t ind) const noexcept;   // returns ind-s left node index
        constexpr size_t right(size_t ind) const noexcept;  // returns ind-s right node index
        void             make_heap();                       // Build a heap from the elements
        void             heapify_down(size_t ind);          // Heapify down the element at given index

    private:
        container_type m_heap; // The vector representing the heap
        size_type      m_size; // The size of the priority queue
        value_compare  m_cmp;  // The comparison function for comparing elements
    };

#include "../src/priority_queue.hpp"

} // namespace my

#endif // THEAP_H