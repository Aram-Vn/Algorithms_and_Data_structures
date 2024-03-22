#include "../include/selection_sort.h"
#include <utility>

void selection_sort(std::vector<int>& arr)
{
    int min_ind = 0;

    for (int i = 0; i < arr.size(); ++i)
    {
        min_ind = i;
        
        for (int j = i + 1; j < arr.size(); ++j)
        {
            if(arr[j] < arr[min_ind])
            {
                min_ind = j;
            }
        }

        if(i != min_ind)
        {
            std::swap(arr[i], arr[min_ind]);
        }
    }
}