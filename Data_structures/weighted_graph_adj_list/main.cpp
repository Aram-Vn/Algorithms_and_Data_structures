#include <exception>
#include <vector>
#include <weighted_graph_adj_list.h>

int main()
{
    my::weighted_graph a{ 7 };

    try
    {
        a.add_edge(0, 1, 12);
        a.add_edge(1, 6, 20);
        a.add_edge(1, 2, 7);
        a.add_edge(1, 4, 30);
        a.add_edge(2, 3, 1);
        a.add_edge(3, 2, 8);
        a.add_edge(3, 4, 42);
        a.add_edge(3, 5, 6);
        a.add_edge(4, 5, 7);
        a.add_edge(5, 4, 17);
        a.add_edge(6, 0, 5);
        a.add_edge(6, 2, 15);
        // a.add_edge(7, 55);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    // a.print();
    // a.dfs(0);
    // a.dfs(0, false);
    // a.bfs(2);
    // a.tarjan_scc();
    // a.kosaraju_scc();

    // my::weighted_graph::AdjacencyList tr = a.transpose();

    // std::cout << "TR" << std::endl;

    // for (std::size_t i = 0; i < tr.size(); ++i)
    // {
    //     std::cout << i << " -> ";

    //     for (const auto& elem : tr[i])
    //     {
    //         std::cout << "e:" << elem.first << " w:" << elem.second << " | ";
    //     }
    //     std::cout << std::endl;
    // }

    std::vector<my::weighted_graph::inf_t> vec;
    try
    {
        a.dijkstra(5, vec);

        for (auto elem : vec)
        {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
