#include "../include/quick_sort.h"
// #include <utility>
// #include <vector>

// int pivotFinder(std::vector<int>& arr, int start, int end)
// {
//     int pivot = arr[end];

//     int i = start - 1;

//     for (int j = start; j <= end - 1; ++j)
//     {
//         if (arr[j] <= pivot)
//         {
//             ++i;
//             std::swap(arr[i], arr[j]);
//         }
//     }

//     std::swap(arr[i + 1], arr[end]);
//     return i + 1;
// }

// void quickSortHelper(std::vector<int>& arr, int start, int end)
// {
//     if (start < end)
//     {
//         int pivotInd = pivotFinder(arr, start, end);

//         quickSortHelper(arr, start, pivotInd - 1);
//         quickSortHelper(arr, pivotInd + 1, end);
//     }
// }

// void quickSort(std::vector<int>& arr)
// {
//     quickSortHelper(arr, 0, arr.size() - 1);
// }

// -------------------------------------------------------------------------------

// #include <utility>
// #include <vector>

// int medianOfThree(std::vector<int>& arr, int start, int end)
// {
//     int mid = start + (end - start) / 2;

//     if (arr[start] > arr[mid])
//         std::swap(arr[start], arr[mid]);
//     if (arr[start] > arr[end])
//         std::swap(arr[start], arr[end]);
//     if (arr[mid] > arr[end])
//         std::swap(arr[mid], arr[end]);

//     return mid;
// }

// int pivotFinder(std::vector<int>& arr, int start, int end)
// {
//     int mid = medianOfThree(arr, start, end);
//     std::swap(arr[mid], arr[end - 1]);

//     int pivot = arr[end - 1];
//     int i = start - 1;

//     for (int j = start; j <= end - 2; ++j)
//     {
//         if (arr[j] <= pivot)
//         {
//             ++i;
//             std::swap(arr[i], arr[j]);
//         }
//     }
//     std::swap(arr[i + 1], arr[end - 1]);
//     return i + 1;
// }

// void quickSortHelper(std::vector<int>& arr, int start, int end)
// {
//     if (start < end)
//     {
//         int pivotInd = pivotFinder(arr, start, end);

//         quickSortHelper(arr, start, pivotInd - 1);
//         quickSortHelper(arr, pivotInd + 1, end);
//     }
// }

// void quickSort(std::vector<int>& arr)
// {
//     quickSortHelper(arr, 0, arr.size() - 1);
// }

// --------------------------------------------------------

// #include <utility>
// #include <vector>

// int medianThree(int a, int b, int c)
// {
//     if ((a > b) ^ (a > c))
//         return a;
//     else if ((b < a) ^ (b < c))
//         return b;
//     else
//         return c;
// }

// int medianOfThree(std::vector<int>& arr, int start, int end)
// {
//     int mid = start + (end - start) / 2;
//     int first = arr[start];
//     int middle = arr[mid];
//     int last = arr[end];

//     int median = medianThree(first, middle, last);

//     if (median == first)
//         return start;
//     else if (median == middle)
//         return mid;
//     else
//         return end;
// }

// int pivotFinder(std::vector<int>& arr, int start, int end)
// {
//     int mid = medianOfThree(arr, start, end);
//     std::swap(arr[mid], arr[start]);

//     int pivot = arr[start];
//     int i = start;

//     for (int j = start + 1; j <= end; ++j)
//     {
//         if (arr[j] <= pivot)
//         {
//             ++i;
//             std::swap(arr[i], arr[j]);
//         }
//     }
//     std::swap(arr[i], arr[start]);
//     return i;
// }

// void quickSortHelper(std::vector<int>& arr, int start, int end)
// {
//     if (start < end)
//     {
//         int pivotInd = pivotFinder(arr, start, end);

//         quickSortHelper(arr, start, pivotInd - 1);
//         quickSortHelper(arr, pivotInd + 1, end);
//     }
// }

// void quickSort(std::vector<int>& arr)
// {
//     quickSortHelper(arr, 0, arr.size() - 1);
// }

// #include <cstdlib>
// #include <ctime>
// #include <utility>
// #include <vector>

// int getRandom(int start, int end)
// {
//     // Generate a random number between start and end
//     return start + rand() % (end - start + 1);
// }

// int pivotFinder(std::vector<int>& arr, int start, int end)
// {
//     // Choose a random index between start and end
//     int pivotIndex = getRandom(start, end);

//     // Swap the pivot element with the last element
//     std::swap(arr[pivotIndex], arr[end]);

//     int pivot = arr[end];
//     int i = start - 1;

//     for (int j = start; j <= end - 1; ++j)
//     {
//         if (arr[j] <= pivot)
//         {
//             ++i;
//             std::swap(arr[i], arr[j]);
//         }
//     }

//     std::swap(arr[i + 1], arr[end]);
//     return i + 1;
// }

// void quickSortHelper(std::vector<int>& arr, int start, int end)
// {
//     if (start < end)
//     {
//         int pivotInd = pivotFinder(arr, start, end);

//         quickSortHelper(arr, start, pivotInd - 1);
//         quickSortHelper(arr, pivotInd + 1, end);
//     }
// }

// void quickSort(std::vector<int>& arr)
// {
//     srand(time(nullptr)); // Seed for random number generation
//     quickSortHelper(arr, 0, arr.size() - 1);
// }

