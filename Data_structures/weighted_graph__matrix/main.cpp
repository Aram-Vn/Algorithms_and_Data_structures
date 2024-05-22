
#include <iostream>
#include <weighted_graph__matrix.h>

int main()
{
    my::weighted_graph_matrix a{ 5 };

    try
    {
        a.add_edge(0, 1, 10);
        a.add_edge(0, 2, 15);
        a.add_edge(0, 4, 15);
        a.add_edge(1, 4, 15);
        a.add_edge(2, 4, 15);
        a.add_edge(2, 3, 15);
        a.add_edge(4, 3, 15);
        a.add_edge(3, 1, 15);

        a.add_vertex();

        a.add_edge(5, 2, 25);
        a.add_edge(2, 5, 25);

        a.add_edge(6, 2, 25);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    my::weighted_graph_matrix::matrix_gr tr = a.transpose();

    a.print();

    std::cout << "TR" << std::endl;

    for (std::size_t i = 0; i < tr.size(); ++i)
    {
        std::cout << i << " -> ";
        for (std::size_t j = 0; j < tr[i].size(); ++j)
        {
            if (tr[i][j] != my::weighted_graph_matrix::no_connection)
            {
                std::cout << j << " (w: " << tr[i][j] << ")"
                          << " | ";
            }
        }
        std::cout << std::endl;
    }

    a.dfs(0);
    a.dfs(0, false);
}
