#include "../../include/quick_sort.h"
#include <cstdlib>
#include <ctime>
#include <utility>
#include <vector>

int getRandom(int start, int end)
{
    return start + rand() % (end - start + 1);
}

int pivotFinder(std::vector<int> &arr, int start, int end)
{
    int pivotIndex = getRandom(start, end);

    std::swap(arr[pivotIndex], arr[end]);

    int pivot = arr[end];
    int i     = start - 1;

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
    srand(time(nullptr));
    quickSortHelper(arr, 0, arr.size() - 1);
}