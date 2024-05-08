#include "../headers/Graph.h"
#include <cstddef>

namespace my {

    Graph::Graph(std::size_t x)
        : m_AdjacencyList(x, std::vector<std::size_t>())
    {
    }

    //-------------------------_add_vertex_---------------------//
    void Graph::add_vertex(std::size_t vertex)
    {
        if (vertex > m_AdjacencyList.size() + 1)
        {
            std::cout << "can't add vertex " << vertex << std::endl;
            throw std::out_of_range("in add_vertex\ncan't add vertex");
        }

        m_AdjacencyList.emplace_back(std::vector<std::size_t>());
    }

    //--------------------------_add_edge_-----------------------//
    void Graph::add_edge(std::size_t vertex1, std::size_t vertex2)
    {
        if (vertex1 >= m_AdjacencyList.size() || vertex2 >= m_AdjacencyList.size())
        {
            throw std::out_of_range("\nfor add_edge\ncan't add edge");
        }

        auto it_v1 = std::find(m_AdjacencyList[vertex1].begin(), m_AdjacencyList[vertex1].end(), vertex2);
        auto it_v2 = std::find(m_AdjacencyList[vertex2].begin(), m_AdjacencyList[vertex2].end(), vertex1);

        if (it_v1 == m_AdjacencyList[vertex1].end() && it_v2 == m_AdjacencyList[vertex2].end())
        {
            if (vertex1 == vertex2)
            {
                m_AdjacencyList[vertex1].push_back(vertex2);
                return;
            }

            m_AdjacencyList[vertex1].push_back(vertex2);
            m_AdjacencyList[vertex2].push_back(vertex1);
        }
        else
        {
            throw std::logic_error("Edge already exists!");
        }
    }

    //-----------------------------_remove_edge_----------------------//
    void Graph::remove_edge(std::size_t vertex1, std::size_t vertex2)
    {
        if (vertex1 >= m_AdjacencyList.size() || vertex2 >= m_AdjacencyList.size())
        {
            throw std::out_of_range("\nfor remove_edge\ncant remove edge");
        }

        auto newEnd = std::remove(m_AdjacencyList[vertex1].begin(), m_AdjacencyList[vertex1].end(), vertex2);
        
        m_AdjacencyList[vertex1].erase(newEnd, m_AdjacencyList[vertex1].end());
    }

    //---------------------------_print_--------------------------//
    void Graph::print() const
    {
        for (std::size_t i = 0; i < m_AdjacencyList.size(); ++i)
        {
            std::cout << i << " -> ";

            for (std::size_t j = 0; j < m_AdjacencyList[i].size(); ++j)
            {
                std::cout << m_AdjacencyList[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

} // namespace my
