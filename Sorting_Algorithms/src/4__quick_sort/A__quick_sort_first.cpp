#include "../../include/quick_sort.h"
#include <vector>

int pivotFinder(std::vector<int> &arr, int start, int end)
{
    int pivot = arr[end];

    int i = start - 1;

    for (int j = start; j <= end - 1; ++j)
    {
        if (arr[j] <= pivot)
        {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[end]);
    return i + 1;
}

void quickSortHelper(std::vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int pivotInd = pivotFinder(arr, start, end);

        quickSortHelper(arr, start, pivotInd - 1);
        quickSortHelper(arr, pivotInd + 1, end);
    }
}

void quickSort(std::vector<int> &arr)
{
    quickSortHelper(arr, 0, arr.size() - 1);
}
