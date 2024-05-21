#include <weighted_graph_adj_list.h>

int main()
{
    my::weighted_graph g(5);
    g.add_edge(0, 2);
    g.add_edge(2, 0);
    g.add_edge(1, 0);
    g.add_edge(2, 1);
    g.add_edge(0, 3);
    g.add_edge(3, 4);

    g.tarjan_scc();
    // EXPECT_EQ(g.transpose()[1][0].second, 0);  // weight of edge (1, 0) in transposed graph should be 0
    // std ::cout << "yy0  " << g.transpose()[1][0].second << std::endl;

    // EXPECT_EQ(g.transpose()[2][1].second, 10); // weight of edge (2, 1) in transposed graph should be 10
    // std ::cout << "yy10  " << g.transpose()[2][0].second << std::endl;
    // EXPECT_NO_THROW(g.add_edge(1, 2, 20));
    // EXPECT_EQ(g.transpose()[2][1].second, 20); // weight of edge (2, 1) should be updated to 20

    /*
        my::weighted_graph a{ 7 };

        try
        {
            a.add_edge(0, 1);
            a.add_edge(1, 6);
            a.add_edge(1, 2);
            a.add_edge(1, 4);
            a.add_edge(2, 3);
            a.add_edge(3, 2);
            a.add_edge(3, 4);
            a.add_edge(3, 5);
            a.add_edge(4, 5);
            a.add_edge(5, 4);
            a.add_edge(6, 0);
            a.add_edge(6, 2);
            a.add_edge(7, 2);
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }

        a.print();
        a.dfs(0);
        a.dfs(0, false);
        a.bfs(2);
        a.tarjan_scc();
        a.kosaraju_scc();
        */
}
