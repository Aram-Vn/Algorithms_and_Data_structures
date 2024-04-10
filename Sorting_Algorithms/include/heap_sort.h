#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <vector>

void heapify(std::vector<int>& vec, size_t ind, size_t heap_size);
void heap_sort(std::vector<int>& vec);

#endif // HEAP_SORT_H