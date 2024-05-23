
#include "../include/weighted_graph__matrix.h"

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
        matrix_gr transposed = m_graph;

        std::size_t size = transposed.size();

        #pragma omp parallel for
        for (std::size_t i = 0; i < size; ++i)
        {
            for (std::size_t j = 0; j < i; ++j)
            {
                std::swap(transposed[i][j], transposed[j][i]);
            }
        }

        return transposed;
    }

    /*------------------------------_-dfs-_-------------------------------*/
    void weighted_graph_matrix::dfs(const vertex_t start_vert, bool print_preorder) const
    {
        std::vector<bool> visited(m_graph.size(), false);

        dfs_util(start_vert, visited, print_preorder);

        for (vertex_t V_vert = 0; V_vert < m_graph.size(); ++V_vert)
        {
            if (!visited[V_vert])
            {
                this->dfs_util(V_vert, visited, print_preorder);
            }
        }

        std::cout << std::endl;
    }

    void weighted_graph_matrix::dfs_util(vertex_t src, std::vector<bool>& visited, bool print_preorder) const
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
                dfs_util(neighbor, visited, print_preorder);
            }
        }

        if (!print_preorder)
        {
            std::cout << src << " ";
        }
    }

    /*------------------------------_-bfs-_-------------------------------*/
    void weighted_graph_matrix::bfs(vertex_t start_vertex) const
    {
        std::vector<bool> visited(m_graph.size(), false);

        this->bfs_util(start_vertex, visited);

        for (vertex_t V_vert = 0; V_vert < m_graph.size(); ++V_vert)
        {
            if (!visited[V_vert])
            {
                bfs_util(V_vert, visited);
            }
        }

        std::cout << std::endl;
    }

    void weighted_graph_matrix::bfs_util(vertex_t start_vert, std::vector<bool>& visited) const
    {
        std::queue<vertex_t> qu;

        qu.push(start_vert);
        visited[start_vert] = true;

        while (!qu.empty())
        {
            vertex_t current_vert = qu.front();
            std::cout << current_vert << " ";
            qu.pop();

            for (vertex_t neighbor = 0; neighbor < m_graph.size(); ++neighbor)
            {
                if (m_graph[current_vert][neighbor] != no_connection && !visited[neighbor])
                {
                    qu.push(neighbor);
                    visited[neighbor] = true;
                }
            }
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
                if (m_graph[i][j] != no_connection)
                {
                    std::cout << m_graph[i][j] << " ";
                }
                else {
                    std::cout << " NO ";
                }
            }
            std::cout << std::endl;
        }

        std::cout << " OO \n";

        for (std::size_t i = 0; i < m_graph.size(); ++i)
        {
            std::cout << i << " -> ";
            for (std::size_t j = 0; j < m_graph[i].size(); ++j)
            {
                if (m_graph[i][j] != no_connection)
                {
                    std::cout << "e:" << j << " w:" << m_graph[i][j] << " | ";
                }
            }
            std::cout << std::endl;
        }
    }
} // namespace my
