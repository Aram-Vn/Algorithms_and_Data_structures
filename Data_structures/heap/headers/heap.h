#ifndef THEAP_H
#define THEAP_H

#include <cstddef>
#include <functional>
#include <iostream>
#include <vector>

namespace my {
    template <typename T, typename Compare = std::less<T>>
    class Heap
    {
        using value_compare = Compare;
        using value_type      = T;
        using size_type       = size_t;
        using const_reference = const T&;
        using container_type  = std::vector<value_type>;

    public:
        ~Heap() = default;           //
        Heap();                      //
        Heap(container_type& input); //

        template <typename RandomAccessIterator>
        Heap(RandomAccessIterator first, RandomAccessIterator last); //

    public:
        size_t          parent(size_t ind);        //
        size_t          left(size_t ind);          //
        size_t          right(size_t i);           //
        void            push(const_reference val); //
        void            pop();                     //
        const_reference top();                     //
        bool            empty();                   //
        size_type       size();                    //
        void            print();                   //

    private:
        void make_heap();              //
        void heapify_down(size_t ind); //

    private:
        container_type m_heap;
        size_type      m_size;
        value_compare  m_cmp;
    };

#include "../src/heap.hpp"

} // namespace my

#endif // THEAP_H