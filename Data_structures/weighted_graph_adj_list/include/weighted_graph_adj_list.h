
#ifndef WEIGHTED_GRAPH_ADJ_LIST_INCLUDE_WEIGHTED_GRAPH_ADJ_LIST_H
#define WEIGHTED_GRAPH_ADJ_LIST_INCLUDE_WEIGHTED_GRAPH_ADJ_LIST_H

#include "UnionFind.h"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <tuple>
#include <utility>
#include <vector>

namespace my {
    // Class representing a weighted graph using an adjacency list representation
    class weighted_graph
    {
    public:
        using vertex_t      = std::size_t;
        using weight_t      = std::int32_t;
        using inf_t         = std::int64_t;
        using Edge          = std::pair<vertex_t, weight_t>;
        using AdjacencyList = std::vector<std::vector<Edge>>;

        static constexpr int64_t INF = std::numeric_limits<int64_t>::max();

    public:
        weighted_graph(std::size_t size, bool is_directed = true);

    public:
        // modifiers
        void add_vertex();
        void add_edge(const vertex_t src_vertex1, const vertex_t vertex2, const weight_t weight = 0);

        // Graph traversal algorithms
        void dfs(const vertex_t start_vert, bool print_preorder = true) const;
        void bfs(const vertex_t start_vert) const;

        // Strongly Connected Components algorithms
        void kosaraju_scc() const;
        void tarjan_scc() const;

        // Graph transposition (mainly for Kosaraju)
        AdjacencyList transpose() const;

        // Topological Sort
        std::stack<vertex_t> topological_sort() const;

        // Shortest Path algorithms
        void dag_SSSP_top_sort(vertex_t start_vertex, std::vector<inf_t>& distances) const;
        void dijkstra(const vertex_t start_vert, std::vector<inf_t>& res) const; // (V + E)log(V)
        bool bellman_ford(vertex_t start_vert, std::vector<inf_t>& distances) const;

        // Minimum Spanning Tree algorithms
        long prims_MST(vertex_t start_vert) const; //
        long kruskal_MST() const;                  //

        // Utility functions
        void print_MST(const std::vector<std::pair<vertex_t, vertex_t>>& mst_edges) const;
        void print_paths(vertex_t start_vert, const std::vector<inf_t>& distances) const;
        void print() const;

    private:
        // Helper methods for DFS and BFS
        void dfs(vertex_t src, std::vector<bool>& visited, bool print_preorder) const;
        void bfs(vertex_t start_vertex, std::vector<bool>& visited) const;

        // Helper methods for Kosaraju's algorithm
        void dfs_kosaraju(vertex_t vertex, std::vector<bool>& visited, std::stack<vertex_t>& finish_stack) const;
        void dfs_transposed(vertex_t vertex, const AdjacencyList& transposed_graph, std::vector<bool>& visited,
                            std::vector<vertex_t>& component) const;

        // Helper method for Tarjan's algorithm
        void tarjan_scc_util(vertex_t vertex, std::vector<long>& ids, std::vector<long>& low,
                             std::vector<bool>& on_stack, std::stack<vertex_t>& stack,
                             std::vector<std::vector<vertex_t>>& sccs, vertex_t& id) const;

        // Helper method for Topological Sort
        bool topological_sort_util(vertex_t cur_vert, std::vector<bool>& visited, std::vector<bool>& rec_stack,
                                   std::stack<vertex_t>& Stack) const;

    private:
        AdjacencyList m_graph;
        bool          m_is_directed;
    };

} // namespace my

#endif // WEIGHTED_GRAPH_ADJ_LIST_INCLUDE_WEIGHTED_GRAPH_ADJ_LIST_H
