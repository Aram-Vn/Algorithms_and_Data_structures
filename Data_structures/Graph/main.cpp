#include <Graph.h>

int main()
{
    my::Graph g{ 11 };
    try
    {
        g.add_edge(0, 1);
        g.add_edge(0, 10);
        g.add_edge(1, 3);
        g.add_edge(1, 2);
        g.add_edge(2, 3);
        g.add_edge(3, 4);
        g.add_edge(4, 10);
        g.add_edge(4, 5);
        g.add_edge(5, 10);
        g.add_edge(5, 6);
        g.add_edge(6, 7);
        g.add_edge(6, 8);
        g.add_edge(7, 9);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Caught unknown exception." << std::endl;
    }

    g.print();
    g.bfs(0);
    g.dfs_rec(0);
    g.dfs_rec(0, false);

    return 0;
}