
#ifndef WEIGHTED_GRAPH__MATRIX_INCLUDE_WEIGHTED_GRAPH__MATRIX_H
#define WEIGHTED_GRAPH__MATRIX_INCLUDE_WEIGHTED_GRAPH__MATRIX_H

#include <cstddef>
#include <cstdint>
#include <iostream>
#include <limits>
#include <queue>
#include <sstream>
#include <stdexcept>
#include <vector>

namespace my {
    class weighted_graph_matrix
    {
    public:
        using weight_t  = std::int64_t;
        using vertex_t  = std::size_t;
        using matrix_gr = std::vector<std::vector<weight_t>>;

        static constexpr weight_t no_connection = std::numeric_limits<weight_t>::max();

    public:
        weighted_graph_matrix(std::size_t size);

    public:
        void add_edge(vertex_t src_vertex1, vertex_t vertex2, weight_t weight); //
        void add_vertex();                                                      //

        void dfs(const vertex_t start_vert, bool print_preorder = true) const; //
        void bfs(vertex_t start_vertex) const;                                 //

        void      print() const;     //
        matrix_gr transpose() const; //

    private:
        void dfs_util(vertex_t src, std::vector<bool>& visited, bool print_preorder) const; //
        void bfs_util(vertex_t start_vert, std::vector<bool>& visited) const;               //

    private:
        matrix_gr m_graph;
    };

} // namespace my

#endif // WEIGHTED_GRAPH__MATRIX_INCLUDE_WEIGHTED_GRAPH__MATRIX_H
