#include <vector>

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

void mergeSortHelper(std::vector<int>& arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void mergeSort(std::vector<int>& arr)
{
    mergeSortHelper(arr, 0, arr.size() - 1);
}