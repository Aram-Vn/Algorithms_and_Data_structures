#ifndef THEAP_H
#define THEAP_H

#include <cstddef>
#include <functional>
#include <iostream>
#include <vector>

namespace my {
    template <typename T, typename Cmp = std::less<T>>
    class Heap
    {
    public:
        ~Heap() = default;
        Heap(std::vector<T> &input, const Cmp &cmp = Cmp());

        template <typename RandomAccessIterator>
        Heap(RandomAccessIterator first, RandomAccessIterator last);

    public:
        size_t   parent(size_t ind);
        size_t   left(size_t ind);
        size_t   right(size_t i);
        void     push(const T &val);
        void     pop();
        const T &top();

    private:
        void make_heap();
        void heapify_down(size_t ind);

    public:
        void print();

    private:
        std::vector<T> m_heap;
        size_t         m_size;
        Cmp            m_cmp;
    };

#include "../src/heap.hpp"

} // namespace my

#endif // THEAP_H