#include "../headers/Graph.h"
#include <cstddef>

namespace my {

    Graph::Graph(std::size_t x)
        : m_graph(x, std::vector<int>())
    {
    }

} // namespace my
