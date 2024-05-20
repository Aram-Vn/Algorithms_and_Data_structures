
#ifndef WEIGHTED_GRAPH_ADJ_LIST_INCLUDE_WEIGHTED_GRAPH_ADJ_LIST_H
#define WEIGHTED_GRAPH_ADJ_LIST_INCLUDE_WEIGHTED_GRAPH_ADJ_LIST_H

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <queue>
#include <stdexcept>
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
        void add_vertex();                                                                             //
        void add_edge(const vertex_type vertex1, const vertex_type vertex2, const weight_type weight); //

        void dfs(const vertex_type start_vert, bool print_preorder = true) const; //
        void bfs(const vertex_type start_vert) const;

        void print() const;

    private:
        void dfs(vertex_type src, std::vector<bool>& visited, bool print_preorder) const; //
        void bfs(vertex_type start_vertex, std::vector<bool>& visited) const;

    private:
        AdjacencyList m_graph;
    };
} // namespace my

#endif // WEIGHTED_GRAPH_ADJ_LIST_INCLUDE_WEIGHTED_GRAPH_ADJ_LIST_H
