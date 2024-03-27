#include "../include/quick_sort.h"

int pivotFinder(std::vector<int>& arr, int start, int end)
{
    int pivotInd = arr[start];

    
}

void quickSortHelper(std::vector<int>& arr, int start, int end)
{
    if (start < end)
    {
        int pivotInd = pivotFinder(arr, start, end);

        quickSortHelper(arr, start, pivotInd - 1);
        quickSortHelper(arr, pivotInd, end);
    }
}

void quickSort(std::vector<int>& arr)
{
    quickSortHelper(arr, 0, arr.size());
}