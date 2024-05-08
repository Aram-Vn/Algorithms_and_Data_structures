#include <Graph.h>

int main()
{
    my::Graph g{ 6 };
    try
    {
        g.add_vertex(2);
        g.add_edge(1, 2);
        g.add_edge(1, 1);
        g.add_edge(1, 1);
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

    return 0;
}