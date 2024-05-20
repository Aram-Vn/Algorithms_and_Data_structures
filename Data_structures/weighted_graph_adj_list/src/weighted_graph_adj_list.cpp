
#include "../include/weighted_graph_adj_list.h"

namespace my {
    weighted_graph::weighted_graph(std::size_t size)
        : m_graph(size)
    {
    }

    //-------------------------_add_vertex_---------------------//
    void weighted_graph::add_vertex()
    {
        m_graph.emplace_back();
    }

    //--------------------------_add_edge_-----------------------//
    void weighted_graph::add_edge(const vertex_type vertex1, const vertex_type vertex2, const weight_type weight)
    {
        if (vertex1 >= m_graph.size() || vertex2 >= m_graph.size())
        {
            throw std::out_of_range("\nfor add_edge\ncan't add edge");
        }

        std::vector<std::pair<vertex_type, weight_type>>& edges = m_graph[vertex1];

        // check if the edge already exists
        std::vector<std::pair<vertex_type, weight_type>>::iterator it =
            std::find_if(edges.begin(), edges.end(),
                         [vertex2](const std::pair<vertex_type, weight_type>& edge) { return edge.first == vertex2; });

        if (it == edges.end()) // if no edge add
        {
            m_graph[vertex1].emplace_back(vertex2, weight);
        }
        else // if exists change weight
        {
            it->second = weight;
        }
    }

    //-----------------------------_-dfs_rec-_----------------------//
    void weighted_graph::dfs(const vertex_type start_vert, bool print_preorder) const
    {
        std::vector<bool> visited(m_graph.size(), false);
        dfs(start_vert, visited, print_preorder);

        for (vertex_type i = 0; i < m_graph.size(); ++i)
        {
            if (visited[i] == false)
            {
                dfs(i, visited, print_preorder);
            }
        }

        std::cout << std::endl;
    }

    void weighted_graph::dfs(vertex_type src, std::vector<bool>& visited, bool print_preorder) const
    {
        visited[src] = true;

        if (print_preorder)
        {
            std::cout << src << " ";
        }

        for (const auto& u_vert : m_graph[src])
        {
            if (!visited[u_vert.first])
            {
                dfs(u_vert.first, visited, print_preorder);
            }
        }

        if (!print_preorder)
        {
            std::cout << src << " ";
        }
    }

    //-----------------------------_-bfs-_----------------------//
    void weighted_graph::bfs(const vertex_type start_vert) const
    {
        std::vector<bool> visited(m_graph.size(), false);
        bfs(start_vert, visited);

        for (vertex_type vertex = 0; vertex < m_graph.size(); ++vertex)
        {
            if (!visited[vertex])
            {
                bfs(vertex, visited);
            }
        }
        std::cout << std::endl;
    }

    void weighted_graph::bfs(vertex_type start_vertex, std::vector<bool>& visited) const
    {
        std::queue<vertex_type> qu;

        qu.push(start_vertex);
        visited[start_vertex] = true;

        while (!qu.empty())
        {
            vertex_type current_vert = qu.front();
            std::cout << current_vert << " ";
            qu.pop();

            for (const auto& neighbor : m_graph[current_vert])
            {
                if (!visited[neighbor.first])
                {
                    qu.push(neighbor.first);
                    visited[neighbor.first] = true;
                }
            }
        }
    }

    //---------------------------_print_--------------------------//
    void weighted_graph::print() const
    {
        for (std::size_t i = 0; i < m_graph.size(); ++i)
        {
            std::cout << i << " -> ";

            for (std::size_t j = 0; j < m_graph[i].size(); ++j)
            {
                std::cout << "e:" << m_graph[i][j].first << " w:" << m_graph[i][j].second << " | ";
            }
            std::cout << std::endl;
        }
    }

} // namespace my
