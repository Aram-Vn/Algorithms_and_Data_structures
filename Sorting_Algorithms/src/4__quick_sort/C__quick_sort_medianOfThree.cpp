#include "../../include/quick_sort.h"
#include <utility>
#include <vector>

int medianOfThree(std::vector<int>& arr, int start, int end)
{
    int mid = start + (end - start) / 2;

    if (arr[start] > arr[mid])
        std::swap(arr[start], arr[mid]);
    if (arr[start] > arr[end])
        std::swap(arr[start], arr[end]);
    if (arr[mid] > arr[end])
        std::swap(arr[mid], arr[end]);

    return mid;
}

int pivotFinder(std::vector<int>& arr, int start, int end)
{
    int mid = medianOfThree(arr, start, end);
    std::swap(arr[mid], arr[end - 1]);

    int pivot = arr[end - 1];
    int i = start - 1;

    for (int j = start; j <= end - 2; ++j)
    {
        if (arr[j] <= pivot)
        {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[end - 1]);
    return i + 1;
}

void quickSortHelper(std::vector<int>& arr, int start, int end)
{
    if (start < end)
    {
        int pivotInd = pivotFinder(arr, start, end);

        quickSortHelper(arr, start, pivotInd - 1);
        quickSortHelper(arr, pivotInd + 1, end);
    }
}

void quickSort(std::vector<int>& arr)
{
    quickSortHelper(arr, 0, arr.size() - 1);
}