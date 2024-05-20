#include <weighted_graph_adj_list.h>

int main()
{
    my::weighted_graph a{ 5 };
    a.add_vertex();
    a.add_vertex();
    a.add_edge(0, 1, 15);
    a.add_edge(0, 1, 25);
    a.add_edge(1, 2, 215);
    a.add_edge(0, 4, 33);
    a.add_edge(3, 1, 25);

    a.print();
    a.dfs(0);
    a.dfs(0, false);
    a.bfs(2);
}
