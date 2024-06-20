#include "../include/heap_sort.h"
#include <cstddef>
#include <utility>

void heap_sort(std::vector<int>& vec)
{
    size_t size = vec.size();

    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        heapify(vec, i, size);
    }

    for (int i = size - 1; i > 0; i--)
    {
        std::swap(vec[0], vec[i]);
        heapify(vec, 0, i);
    }
}

void heapify(std::vector<int>& vec, size_t ind, size_t heap_size)
{
    size_t largest = ind;
    size_t left    = 2 * ind + 1;
    size_t right   = 2 * ind + 2;

    if (left < heap_size && vec[left] > vec[largest])
    {
        largest = left;
    }

    if (right < heap_size && vec[right] > vec[largest])
    {
        largest = right;
    }

    if (largest != ind)
    {
        std::swap(vec[ind], vec[largest]);
        heapify(vec, largest, heap_size);
    }
}
