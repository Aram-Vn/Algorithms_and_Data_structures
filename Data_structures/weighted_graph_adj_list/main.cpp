#include <exception>
#include <vector>
#include <weighted_graph_adj_list.h>

int main()
{
    my::weighted_graph a{ 10, true };

    try
    {
        /*DAG*/
        // a.add_edge(1, 2, 5);
        // a.add_edge(2, 3, -1);
        // a.add_edge(2, 4, 11);
        // a.add_edge(3, 4, 15);
        // a.add_edge(3, 6, 3);
        // a.add_edge(3, 8, 5);
        // a.add_edge(3, 5, 5);
        // a.add_edge(4, 5, 20);
        // a.add_edge(5, 9, 1);
        // a.add_edge(5, 7, 11);
        // a.add_edge(6, 7, 0);
        // a.add_edge(6, 8, 1);

        /*no neg edge, cycled*/
        // a.add_edge(0, 1, 12);
        // a.add_edge(1, 6, 20);
        // a.add_edge(1, 2, 7);
        // a.add_edge(1, 4, 30);
        // a.add_edge(2, 3, 1);
        // a.add_edge(3, 2, 8);
        // a.add_edge(3, 4, 42);
        // a.add_edge(3, 5, 6);
        // a.add_edge(4, 5, 7);
        // a.add_edge(5, 4, 17);
        // a.add_edge(6, 0, 5);
        // a.add_edge(6, 2, 15);
        // a.add_edge(7, 55);

        /*second  try negative-weight cycle.*/
        a.add_edge(0, 1, 5);
        a.add_edge(1, 6, 60);
        a.add_edge(1, 5, 30);
        a.add_edge(1, 2, 3);
        a.add_edge(2, 3, 10);
        a.add_edge(2, 4, 75);
        a.add_edge(3, 2, -15);
        a.add_edge(4, 9, 100);
        a.add_edge(5, 4, 25);
        a.add_edge(5, 6, 5);
        a.add_edge(5, 8, 50);
        a.add_edge(6, 7, -50);
        a.add_edge(7, 8, -10);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    a.print();
    // a.dfs(0);
    // a.dfs(0, false);
    // a.bfs(2);
    // a.tarjan_scc();
    // a.kosaraju_scc();

    my::weighted_graph::AdjacencyList tr = a.transpose();

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

    // std::cout << a.prims_MST(0) << "  mst " << std::endl;
    // std::cout << a.kruskal_MST() << "  mst " << std::endl;
    a.kosaraju_scc();

    std::vector<my::weighted_graph::inf_t> distances;
    if (a.bellman_ford(1, distances))
    {
        std::cout << "NO cycle!!!.\n";
    }
    else
    {
        std::cout << "negative-weight cycle.\n";
    }

    try
    {
        a.dijkstra(1, distances);

        for (auto elem : distances)
        {
            std::cout << elem << " ";
        }
        std::cout << std::endl;

        std::cout << " dag_SSSP_top_sort \n";

        a.dag_SSSP_top_sort(5, distances);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
