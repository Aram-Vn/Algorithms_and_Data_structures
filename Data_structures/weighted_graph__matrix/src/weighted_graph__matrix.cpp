
#include "../include/weighted_graph__matrix.h"
#include <limits>
#include <vector>

namespace my {
    weighted_graph_matrix::weighted_graph_matrix(std::size_t size)
        : m_graph(size, std::vector<weight_t>(size, no_connection))
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

    /*------------------------------_-add_vertex-_-------------------------------*/
    void weighted_graph_matrix::add_vertex()
    {
        m_graph.push_back(std::vector<weight_t>(m_graph.size() + 1, no_connection));

        for (std::size_t i = 0; i < m_graph.size() - 1; ++i)
        {
            m_graph[i].push_back(no_connection);
        }
    }

    /*------------------------------_-transpose-_-------------------------------*/
    weighted_graph_matrix::matrix_gr weighted_graph_matrix::transpose() const
    {
        matrix_gr transposed(m_graph[0].size(), std::vector<weight_t>(m_graph.size(), no_connection));

        for (vertex_t V_vert = 0; V_vert < m_graph.size(); ++V_vert)
        {
            for (vertex_t U_vert = 0; U_vert < m_graph[V_vert].size(); ++U_vert)
            {
                transposed[U_vert][V_vert] = m_graph[V_vert][U_vert];
            }
        }

        return transposed;
    }

    /*------------------------------_-dfs-_-------------------------------*/
    void weighted_graph_matrix::dfs(const vertex_t start_vert, bool print_preorder) const
    {
        std::vector<bool> visited(m_graph.size(), false);

        dfs(start_vert, visited, print_preorder);

        for (vertex_t V_vert = 0; V_vert < m_graph.size(); ++V_vert)
        {
            if (visited[V_vert] == false)
            {
                dfs(V_vert, visited, print_preorder);
            }
        }

        std::cout << std::endl;
    }

    void weighted_graph_matrix ::dfs(vertex_t src, std::vector<bool>& visited, bool print_preorder) const
    {
        visited[src] = true;

        if (print_preorder)
        {
            std::cout << src << " ";
        }

        for (vertex_t neighbor = 0; neighbor < m_graph.size(); ++neighbor)
        {
            if (m_graph[src][neighbor] != no_connection && !visited[neighbor])
            {
                dfs(neighbor, visited, print_preorder);
            }
        }

        if (!print_preorder)
        {
            std::cout << src << " ";
        }
    }

    /*------------------------------_-print-_-------------------------------*/
    void weighted_graph_matrix::print() const
    {
        for (std::size_t i = 0; i < m_graph.size(); ++i)
        {
            std::cout << i << " -> ";
            for (std::size_t j = 0; j < m_graph[i].size(); ++j)
            {
                if (m_graph[i][j] != no_connection) // <long>::max() means no connection
                {
                    std::cout << j << " (w: " << m_graph[i][j] << ")"
                              << " | ";
                }
            }
            std::cout << std::endl;
        }
    }
} // namespace my
