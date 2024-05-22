
#include <iostream>
#include <weighted_graph__matrix.h>

int main()
{
    my::weighted_graph_matrix a{ 5 };

    a.add_edge(0, 1, 10);
    a.add_edge(0, 2, 15);
    a.add_edge(0, 4, 15);
    a.add_edge(1, 4, 15);
    a.add_edge(2, 4, 15);
    a.add_edge(2, 3, 15);
    a.add_edge(4, 3, 15);
    a.add_edge(3, 1, 15);

    a.print();
}
