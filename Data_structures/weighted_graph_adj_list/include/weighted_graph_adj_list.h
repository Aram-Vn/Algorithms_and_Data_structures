
#ifndef WEIGHTED_GRAPH_ADJ_LIST_INCLUDE_WEIGHTED_GRAPH_ADJ_LIST_H
#define WEIGHTED_GRAPH_ADJ_LIST_INCLUDE_WEIGHTED_GRAPH_ADJ_LIST_H

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <queue>
#include <stack>
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
        void add_vertex();                                                                                 //
        void add_edge(const vertex_type vertex1, const vertex_type vertex2, const weight_type weight = 0); //

        void dfs(const vertex_type start_vert, bool print_preorder = true) const; //
        void bfs(const vertex_type start_vert) const;

        AdjacencyList transpose() const;

        void kosaraju_scc() const;
        void tarjan_scc() const; //

        void print() const; //

    private:
        void dfs(vertex_type src, std::vector<bool>& visited, bool print_preorder) const; //
        void bfs(vertex_type start_vertex, std::vector<bool>& visited) const;             //

        void dfs_kosaraju(vertex_type vertex, std::vector<bool>& visited,
                          std::stack<vertex_type>& finish_stack) const; //
        void dfs_transposed(vertex_type vertex, const AdjacencyList& transposed_graph, std::vector<bool>& visited,
                            std::vector<vertex_type>& component) const; //

        void tarjan_scc_util(vertex_type vertex, std::vector<long>& ids, std::vector<long>& low,
                             std::vector<bool>& on_stack, std::stack<vertex_type>& stack,
                             std::vector<std::vector<vertex_type>>& sccs, vertex_type& id) const; //

    private:
        AdjacencyList m_graph;
    };
} // namespace my

#endif // WEIGHTED_GRAPH_ADJ_LIST_INCLUDE_WEIGHTED_GRAPH_ADJ_LIST_H
