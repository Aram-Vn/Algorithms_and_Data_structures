#include <deque>
#include <functional>
#include <iostream>
#include <priority_queue.h>
#include <vector>

int main()
{
    std::vector<int> input = { 30, 10, 20 };

    auto custom_cmp = [](int a, int b)
    {
        return a > b; // Max-heap behavior
    };

    int                                           arr[] = { 30, 10, 20 };
    my::priority_queue<int, decltype(custom_cmp)> pq3(std::begin(arr), std::end(arr), custom_cmp);

    my::priority_queue<int> pq4(std::begin(arr), std::end(arr));

    my::priority_queue<int, decltype(custom_cmp)> pq2({ 30, 10, 20 }, custom_cmp);

    my::priority_queue<int, decltype(custom_cmp), std::vector<int>> pq1(input, custom_cmp);

    my::priority_queue<int, decltype(custom_cmp)> pq(custom_cmp);

    pq.push(10);
    pq.push(30);
    pq.push(20);

    pq.print();

    std::vector<int>        vec = { 3, 2, 4, 1, 5, 9, 10, 55, 88, 77, 12 };
    my::priority_queue<int> min(vec);
    min.print_level();

    my::priority_queue<int, std::less<int>, std::deque<int>> re = { 3, 2, 4, 1, 5, 9, 10, 55, 88, 77, 12 };
    re.print_level();

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

    std::cout << a.extract_top() << std::endl;
    std::cout << a.extract_top() << std::endl;
}
