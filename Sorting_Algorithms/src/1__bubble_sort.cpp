// Տրված ամբողջ թվային զանգվածը սորտավորել Bubble Sort ալգորիթմով

#include "../include/bubble_sort.h"
#include <utility>
#include <vector>

void bubble_sort(std::vector<int>& vec)
{
    bool flag = true;

    for (int i = 0; i < vec.size(); ++i)
    {
        for (int j = 0; j < vec.size() - 1 - i; ++j)
        {
            if (vec[j] > vec[j + 1])
            {
                std::swap(vec[j], vec[j + 1]);
                flag = false;
            }
        }

        if (flag)
        {
            break;
        }
        flag = true;
    }
}
