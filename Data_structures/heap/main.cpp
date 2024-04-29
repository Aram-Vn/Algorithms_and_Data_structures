#include <iostream>
#include <priority_queue.h>
#include <vector>

int main()
{
    std::vector<int>        vec = { 3, 2, 4, 1, 5, 9, 10, 55, 88, 77, 12 };
    my::priority_queue<int> min(vec);
    min.print_level();

    my::priority_queue<int, std::greater<int>> max(vec);
    max.print();

    my::priority_queue<int> h(vec.begin() + 3, vec.end());
    h.print();


    my::priority_queue<int> a;

    if (!h.empty())
    {
        a.push(3);
        a.push(2);
        a.push(4);
        a.push(1);
        a.push(5);
        a.push(9);

        a.print();
    }

    std::cout << a.size();
}