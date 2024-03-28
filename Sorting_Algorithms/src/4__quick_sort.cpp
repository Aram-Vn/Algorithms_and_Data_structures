#include "../include/quick_sort.h"
#include <utility>
#include <vector>

int pivotFinder(std::vector<int>& arr, int start_p, int end_r)
{
    int pivotInd_x = arr[end_r];

    int i = start_p - 1;

    for (int j = start_p; j <= end_r - 1; ++j)
    {
        if (arr[j] <= pivotInd_x)
        {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[end_r]);
    return i + 1;
}

void quickSortHelper(std::vector<int>& arr, int start_p, int end_r)
{
    if (start_p < end_r)
    {
        int pivotInd = pivotFinder(arr, start_p, end_r);

        quickSortHelper(arr, start_p, pivotInd - 1);
        quickSortHelper(arr, pivotInd + 1, end_r);
    }
}

void quickSort(std::vector<int>& arr)
{
    quickSortHelper(arr, 0, arr.size() - 1);
}
