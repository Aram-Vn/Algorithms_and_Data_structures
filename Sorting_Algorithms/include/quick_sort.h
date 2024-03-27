#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <vector>

int pivotFinder(std::vector<int>& arr, int start, int end);
void quickSortHelper(std::vector<int>& arr, int start, int end);
void quickSort(std::vector<int>& arr);

#endif // QUICK_SORT_H