
#include "../include/weighted_graph__matrix.h"
#include <cstddef>
#include <vector>

namespace my {
    weighted_graph_matrix::weighted_graph_matrix(std::size_t size)
        : m_graph{ size, std::vector<weight_t>(size, 0) }
    {
    }

    /*------------------------------_-add_edge-_-------------------------------*/
    void weighted_graph_matrix::add_edge(vertex_t src_vertex1, vertex_t vertex2, weight_t weight)
    {
        if (src_vertex1 >= m_graph.size() || vertex2 >= m_graph.size())
        {
            std::ostringstream errorMessage;

            if (src_vertex1 >= m_graph.size() && vertex2 >= m_graph.size())
            {
                errorMessage << "Cannot add edge:\nvertex: " << src_vertex1 << " and vertex: " << vertex2
                             << " are out of range";
            }
            else if (src_vertex1 >= m_graph.size())
            {
                errorMessage << "Cannot add edge:\n vertex " << src_vertex1 << " is out of range";
            }
            else
            {
                errorMessage << "Cannot add edge:\n vertex " << vertex2 << " is out of range";
            }

            throw std::out_of_range(errorMessage.str());
        }

        m_graph[src_vertex1][vertex2] = weight;
    }

    /*------------------------------_-print-_-------------------------------*/
    void weighted_graph_matrix::print() const
    {
        for (std::size_t i = 0; i < m_graph.size(); ++i)
        {
            std::cout << i << " -> ";
            for (std::size_t j = 0; j < m_graph[i].size(); ++j)
            {
                if (m_graph[i][j] != 0) // 0 means no edge
                {
                    std::cout << j << " (w: " << m_graph[i][j] << ")"
                              << " | ";
                }
            }
            std::cout << std::endl;
        }
    }
} // namespace my
