#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <vector>

int getRandom(int start, int end);
int medianOfThree(std::vector<int>& arr, int start, int end);
int pivotFinder(std::vector<int>& arr, int start, int end);
void quickSortHelper(std::vector<int>& arr, int start, int end);
void quickSort(std::vector<int>& arr);

#endif // QUICK_SORT_H