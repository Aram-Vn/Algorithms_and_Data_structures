#include <heap.h>
#include <vector>

int main()
{
    std::vector<int> vec = { 3, 2, 4, 1, 5, 9 };
    my::Heap<int>    min(vec);
    min.print();

    my::Heap<int, std::greater<int>> max (vec);
    max.print();

    my::Heap<int> h(vec.begin() + 3, vec.end());
    h.print();

    my::Heap<int> a;

    a.push(3);
    a.push(2);
    a.push(4);
    a.push(1);
    a.push(5);
    a.push(9);

    a.print();
}