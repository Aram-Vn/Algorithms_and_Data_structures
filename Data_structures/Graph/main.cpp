#include <Graph.h>
#include <stdexcept>

int main()
{
    my::Graph g{ 11, true };

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
        g.add_edge(9, 8);
        g.add_edge(8, 9);
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

    std::cout << "dfs_iter" << std::endl;
    g.dfs_iter(0);

    std::cout << "bfs" << std::endl;
    g.bfs(0);

    std::cout << "dfs_rec" << std::endl;
    g.dfs_rec(0);
    g.dfs_rec(0, false);

    if (g.has_cicle())
    {
        std::cout << "yes" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
    }

    try
    {
        g.Topological_sort();
    }
    catch (const std::logic_error& e)
    {
        std::cout << e.what();
    }

    return 0;
}
