#include "../include/Thread_MergeSort.h"

void merge(std::vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftIdx  = left;
    int rightIdx = mid + 1;

    std::vector<int> merged;
    merged.reserve(n1 + n2);

    while (leftIdx <= mid && rightIdx <= right)
    {
        if (arr[leftIdx] <= arr[rightIdx])
        {
            merged.push_back(arr[leftIdx]);
            leftIdx++;
        }
        else
        {
            merged.push_back(arr[rightIdx]);
            rightIdx++;
        }
    }

    while (leftIdx <= mid)
    {
        merged.push_back(arr[leftIdx]);
        leftIdx++;
    }

    while (rightIdx <= right)
    {
        merged.push_back(arr[rightIdx]);
        rightIdx++;
    }

    for (int i = left; i <= right; i++)
    {
        arr[i] = merged[i - left];
    }
}

void mergeSort(std::vector<int>& arr, int left, int right, int depth)
{
    if (left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;

    if (depth > 0)
    {
        std::thread t1(mergeSort, std::ref(arr), left, mid, depth - 1);
        std::thread t2(mergeSort, std::ref(arr), mid + 1, right, depth - 1);

        if (t1.joinable())
        {
            t1.join();
        }

        if (t2.joinable())
        {
            t2.join();
        }
    }
    else
    {
        mergeSort(arr, left, mid, 0);
        mergeSort(arr, mid + 1, right, 0);
    }

    merge(arr, left, mid, right);
}
