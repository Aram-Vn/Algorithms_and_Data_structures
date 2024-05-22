
#ifndef WEIGHTED_GRAPH__MATRIX_INCLUDE_WEIGHTED_GRAPH__MATRIX_H
#define WEIGHTED_GRAPH__MATRIX_INCLUDE_WEIGHTED_GRAPH__MATRIX_H

#include <cstddef>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

namespace my {
    class weighted_graph_matrix
    {
    public:
        using weight_t  = long;
        using vertex_t  = std::size_t;
        using matrix_gr = std::vector<std::vector<weight_t>>;

    public:
        weighted_graph_matrix(std::size_t size);

    public:
        void add_edge(vertex_t src_vertex1, vertex_t vertex2, weight_t weight); //

        void print() const; //

    private:
        matrix_gr m_graph;
    };
} // namespace my

#endif // WEIGHTED_GRAPH__MATRIX_INCLUDE_WEIGHTED_GRAPH__MATRIX_H
