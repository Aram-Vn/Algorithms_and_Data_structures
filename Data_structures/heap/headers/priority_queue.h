#ifndef THEAP_H
#define THEAP_H

#include <cstddef>
#include <functional>
#include <iostream>
#include <vector>

namespace my {
    template <typename T, typename Compare = std::less<T>, typename Container = std::vector<T>>
    class priority_queue
    {
        using container_type  = Container;
        using value_compare   = Compare;
        using value_type      = typename Container::value_type;
        using size_type       = typename Container::size_type;
        using reference       = typename Container::reference;
        using const_reference = typename Container::const_reference;

    public:
        ~priority_queue() noexcept {}
        priority_queue();
        priority_queue(const container_type& input);

        template <typename RandomAccessIterator>
        priority_queue(RandomAccessIterator first, RandomAccessIterator last); // gets std::vector iterators

    public:
        // Modifiers
        void       push(const_reference val); // Insert a value into the priority queue
        void       pop();                     // Remove the top element from the priority queue
        value_type extract_top();             // Extracts and returns the top element from the priority queue.

        // Queries
        constexpr const_reference top() const;                    // Get the top element of the priority queue
        constexpr bool            empty() const noexcept;         // Check if the priority queue is empty
        constexpr size_type       size() const noexcept;          // Get the number of elements in the priority queue
        void                      print() const noexcept;         // Print the elements of the priority queue
        void                      print_level() const noexcept;   // Print the elements of the priority queue by level
        constexpr bool            is_valid_heap() const noexcept; // check if is valid priority_queue

    private:
        // Helpers
        constexpr size_t parent(const size_t ind) const noexcept; // returns parent index
        constexpr size_t left(const size_t ind) const noexcept;   // returns ind-s left node index
        constexpr size_t right(const size_t ind) const noexcept;  // returns ind-s right node index
        void             make_heap();                             // Build a heap from the elements
        void             heapify_down(const size_t ind);          // Heapify down the element at given index

    private:
        container_type m_heap; // The vector representing the heap
        size_type      m_size; // The size of the priority queue
        value_compare  m_cmp;  // The comparison function for comparing elements
    };

} // namespace my

#include "../src/priority_queue.hpp"

#endif // THEAP_H