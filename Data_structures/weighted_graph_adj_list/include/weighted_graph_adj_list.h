
#ifndef WEIGHTED_GRAPH_ADJ_LIST_INCLUDE_WEIGHTED_GRAPH_ADJ_LIST_H
#define WEIGHTED_GRAPH_ADJ_LIST_INCLUDE_WEIGHTED_GRAPH_ADJ_LIST_H

#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>

namespace my {
    class weighted_graph
    {
    public:
        using vertex_type   = std::size_t;
        using weight_type   = int;
        using AdjacencyList = std::vector<std::vector<std::pair<vertex_type, weight_type>>>;

    public:
        weighted_graph(std::size_t size); //

    public:
        void dfs(vertex_type src, bool print_preorder = true) const;
        void add_vertex();                                                           //
        void add_edge(vertex_type vertex1, vertex_type vertex2, weight_type weight); //

        void print() const;

    private:
        void dfs(vertex_type src, std::vector<bool>& visited, bool print_preorder) const;

    private:
        AdjacencyList m_graph;
    };
} // namespace my

#endif // WEIGHTED_GRAPH_ADJ_LIST_INCLUDE_WEIGHTED_GRAPH_ADJ_LIST_H