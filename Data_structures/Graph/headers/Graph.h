#ifndef DATA_STRUCTURES_GRAPH_HEADERS_GRAPH_H
#define DATA_STRUCTURES_GRAPH_HEADERS_GRAPH_H

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

namespace my {
    class Graph
    {
    public:
        Graph(std::size_t x);
        ~Graph(){};

    public:
        void add_vertex(std::size_t vertex);
        void add_edge(std::size_t vertex1, std::size_t vertex2);
        void remove_edge(std::size_t vertex1, std::size_t vertex2);
        void print() const;

    private:
        std::vector<std::vector<std::size_t>> m_AdjacencyList;
        // std::size_t                           m_size;
    };
} // namespace my

#endif // DATA_STRUCTURES_GRAPH_HEADERS_GRAPH_H