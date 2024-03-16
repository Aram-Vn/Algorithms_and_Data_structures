#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

int maxSum(std::vector<int>& arr, int k);
int maxSubarraySum(std::vector<int>& nums, int k);

int main()
{
    std::vector<int> arr = { 1, 4, 2, 10, 2, 3, 1, 0, 20 };

    std::cout << "enter K" << std::endl;
    int k = 0;
    std::cin >> k;

    std::cout << maxSum(arr, k) << std::endl;
    std::cout << maxSubarraySum(arr, k) << std::endl;
}

int maxSum(std::vector<int>& arr, int k)
{
    int size = arr.size();

    if (k > size)
    {
        std::cout << "Invalid K" << std::endl;
        return std::numeric_limits<int>::min();
    }

    int max_sum = 0;

    for (int i = 0; i < k; ++i)
    {
        max_sum += arr[i];
    }

    int window_sum = max_sum;

    for (int i = k; i < size; ++i)
    {
        window_sum += arr[i] - arr[i - k];
        max_sum = std::max(max_sum, window_sum);
    }

    return max_sum;
}

int maxSubarraySum(std::vector<int>& nums, int k)
{
    int size = nums.size();
    int windowSum = 0;
    int maxSum = std::numeric_limits<int>::min();

    if (k > size)
    {
        return maxSum;
    }

    for (int i = 0; i < size; ++i)
    {
        windowSum += nums[i];
        if (i >= k - 1)
        {
            maxSum = std::max(maxSum, windowSum);
            windowSum -= nums[i - (k - 1)];
        }
    }

    return maxSum;
}