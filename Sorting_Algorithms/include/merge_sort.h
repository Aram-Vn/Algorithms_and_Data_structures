#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right);
void mergeSortHelper(std::vector<int>& arr, int left, int right);
void mergeSort(std::vector<int>& arr);

#endif // MERGE_SORT_H