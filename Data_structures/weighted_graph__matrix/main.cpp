
#include <iostream>
#include <weighted_graph__matrix.h>

int main()
{
    my::weighted_graph_matrix a{ 7 };

    try
    {
        a.add_edge(0, 1, 10);
        a.add_edge(1, 6, 25);
        a.add_edge(1, 2, 10);
        a.add_edge(1, 4, -7);
        a.add_edge(2, 3, 88);
        a.add_edge(3, 2, 21);
        a.add_edge(3, 4, 14);
        a.add_edge(3, 5, 8);
        a.add_edge(4, 5, 0);
        a.add_edge(5, 4, 11);
        a.add_edge(6, 0, 14);
        a.add_edge(6, 2, 25);
        a.add_edge(7, 55, 12);
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
                std::cout << tr[i][j] << " ";
            }
            else
            {
                std::cout << " NO ";
            }
        }
        std::cout << std::endl;
    }

    std::cout << " OO \n";

    for (std::size_t i = 0; i < tr.size(); ++i)
    {
        std::cout << i << " -> ";
        for (std::size_t j = 0; j < tr[i].size(); ++j)
        {
            if (tr[i][j] != my::weighted_graph_matrix::no_connection)
            {
                std::cout << "e:" << j << " w:" << tr[i][j] << " | ";
            }
        }
        std::cout << std::endl;
    }

    a.dfs(0);
    a.dfs(0, false);
    a.bfs(0);
}
