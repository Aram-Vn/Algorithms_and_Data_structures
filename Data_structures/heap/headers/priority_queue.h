#ifndef HEAP_HEADERS_PRIORITY_QUEUE_H
#define HEAP_HEADERS_PRIORITY_QUEUE_H

#include <cstddef>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <vector>

    namespace my {
    template <typename T, typename Compare = std::less<T>, typename Container = std::vector<T>>
    class priority_queue
    {
    public:
        using container_type  = Container;
        using value_compare   = Compare;
        using value_type      = typename Container::value_type;
        using size_type       = typename Container::size_type;
        using reference       = typename Container::reference;
        using const_reference = typename Container::const_reference;

    private:
        using index_t = std::size_t;

    public:
        // Constructors and destructor
        ~priority_queue() noexcept {}
        explicit priority_queue(const value_compare& cmp = value_compare());
        priority_queue(const container_type& input, const value_compare& cmp = value_compare());
        priority_queue(std::initializer_list<value_type> initList, const value_compare& cmp = value_compare());

        template <typename RandomAccessIterator>
        priority_queue(RandomAccessIterator first, RandomAccessIterator last,
                       const value_compare& cmp = value_compare());

    public:
        // Copy constructor and copy assignment operator
        priority_queue(const priority_queue& other);
        priority_queue& operator=(const priority_queue& other);

        // Move constructor and move assignment operator
        priority_queue(priority_queue&& other) noexcept;
        priority_queue& operator=(priority_queue&& other) noexcept;

    public:
        // Modifiers
        void       push(const_reference val); // Insert a value into the priority queue
        void       pop();                     // Remove the top element from the priority queue
        value_type extract_top();             // Extracts and returns the top element from the priority queue.

        // Queries
        inline const_reference top() const;                    // Get the top element of the priority queue
        inline bool            empty() const noexcept;         // Check if the priority queue is empty
        inline size_type       size() const noexcept;          // Get the number of elements in the priority queue
        bool                   is_valid_heap() const noexcept; // check if is valid priority_queue

        // printing
        void print() const noexcept;       // Print the elements of the priority queue
        void print_level() const noexcept; // Print the elements of the priority queue by level

    private:
        // Helpers
        inline index_t parent(const index_t ind) const noexcept; // returns parent index
        inline index_t left(const index_t ind) const noexcept;   // returns ind-s left node index
        inline index_t right(const index_t ind) const noexcept;  // returns ind-s right node index
        void           make_heap();                              // Build a heap from the elements
        void           heapify_down(const index_t ind);          // Heapify down the element at given index

    private:
        container_type m_heap; // The vector representing the heap
        size_type      m_size; // The size of the priority queue
        value_compare  m_cmp;  // The comparison function for comparing elements
    };

} // namespace my

#include "../src/priority_queue.hpp"

#endif // HEAP_HEADERS_PRIORITY_QUEUE_H