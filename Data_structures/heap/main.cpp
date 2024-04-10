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

    std::cout << min.top() << std::endl;
    min.print();

    std::cout << min.top() << std::endl;
    min.print();

    std::cout << max.top() << std::endl;
    max.print();

    std::cout << max.top() << std::endl;
    max.print();
}