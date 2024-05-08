#ifndef DATA_STRUCTURES_GRAPH_HEADERS_GRAPH_H
#define DATA_STRUCTURES_GRAPH_HEADERS_GRAPH_H

#include <cstddef>
#include <vector>

namespace my {
    class Graph
    {
    public:
        Graph(std::size_t x);
        ~Graph(){};

    private:
        std::vector<std::vector<int>> m_graph;
    };
} // namespace my

#endif // DATA_STRUCTURES_GRAPH_HEADERS_GRAPH_H