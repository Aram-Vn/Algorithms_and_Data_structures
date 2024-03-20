#include "../include/insertion_sort.h"
#include <vector>

void insertion_sort(std::vector<int>& vec)
{
    int tmp = 0;

    for (int i = 1; i < vec.size(); ++i)
    {
        tmp = vec[i];
        int j = i - 1;

        while (j >= 0 && vec[j] > tmp)
        {
            vec[j + 1] = vec[j];
            --j;
        }

        vec[j + 1] = tmp;
    }
}
