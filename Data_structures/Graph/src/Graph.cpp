#include "../headers/Graph.h"

namespace my {

    Graph::Graph(std::size_t x, bool is_directed)
        : m_AdjacencyList(x, std::vector<std::size_t>()),
          m_is_directed(is_directed)
    {
    }

    //-------------------------_add_vertex_---------------------//
    void Graph::add_vertex()
    {
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

        //*******____graph is directed____*******//
        if (m_is_directed)
        {
            if (it_v1 == m_AdjacencyList[vertex1].end())
            {
                if (vertex1 == vertex2)
                {
                    m_AdjacencyList[vertex1].push_back(vertex2);
                    return;
                }

                m_AdjacencyList[vertex1].push_back(vertex2);
                if (m_is_directed == false)
                {
                    m_AdjacencyList[vertex2].push_back(vertex1);
                }

                return;
            }
            else
            {
                throw std::logic_error("Edge already exists!");
            }
        }

        //*******____graph is undirected____*******//
        auto it_v2 = std::find(m_AdjacencyList[vertex2].begin(), m_AdjacencyList[vertex2].end(), vertex1);

        if (it_v1 == m_AdjacencyList[vertex1].end() && it_v2 == m_AdjacencyList[vertex2].end())
        {
            if (vertex1 == vertex2)
            {
                m_AdjacencyList[vertex1].push_back(vertex2);
                return;
            }

            m_AdjacencyList[vertex1].push_back(vertex2);
            if (m_is_directed == false)
            {
                m_AdjacencyList[vertex2].push_back(vertex1);
            }
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

        if (m_is_directed == false)
        {
            auto newEnd_2 = std::remove(m_AdjacencyList[vertex2].begin(), m_AdjacencyList[vertex2].end(), vertex1);
            m_AdjacencyList[vertex2].erase(newEnd_2, m_AdjacencyList[vertex2].end());
        }
    }

    //-----------------------------_-dfs_rec-_----------------------//
    void Graph::dfs_rec(std::size_t vert, bool flag)
    {
        std::vector<bool> visited(m_AdjacencyList.size(), false);

        std::function<void(std::size_t vert)> dfs_lambda = [this, &dfs_lambda, &visited, flag](std::size_t vert) -> void
        {
            visited[vert] = true;
            if (flag)
            {
                std::cout << vert << " "; // preorder
            }

            for (const auto u_vert : m_AdjacencyList[vert])
            {
                if (!visited[u_vert])
                {
                    dfs_lambda(u_vert);
                }
            }
            if (!flag)
            {
                std::cout << vert << " "; // postorder
            }
        };

        dfs_lambda(vert);
        std::cout << std::endl;
    }

    //-----------------------------_-dfs_iter-_----------------------//
    void Graph::dfs_iter(std::size_t vert)
    {
        std::vector<bool>       visited(m_AdjacencyList.size(), false);
        std::stack<std::size_t> stack;

        stack.push(vert);
        visited[vert] = true;

        while (!stack.empty())
        {
            std::size_t current_vertex = stack.top();
            std::cout << current_vertex << " ";
            stack.pop();

            for (const auto neighbor : m_AdjacencyList[current_vertex])
            {
                if (!visited[neighbor])
                {
                    stack.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        std::cout << std::endl;
    }

    //-----------------------------_-bfs-_----------------------//
    void Graph::bfs(std::size_t start_vertex)
    {
        std::vector<bool>       visited(m_AdjacencyList.size(), false);
        std::queue<std::size_t> qu;

        qu.push(start_vertex);
        visited[start_vertex] = true;

        while (!qu.empty())
        {
            std::size_t current_vertex = qu.front();
            std::cout << current_vertex << " ";
            qu.pop();

            for (const auto neighbor : m_AdjacencyList[current_vertex])
            {
                if (!visited[neighbor])
                {
                    qu.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        std::cout << std::endl;
    }

    //---------------------------_-has_cicle-_--------------------------//
    bool Graph::has_cicle()
    {
        std::unordered_set<std::size_t> visited;
        std::unordered_set<std::size_t> current_path;
        bool                            hasCycle = false;

        //*******____graph is directed____*******//
        if (m_is_directed)
        {
            for (std::size_t i = 0; i < m_AdjacencyList.size(); ++i)
            {
                if (visited.find(i) == visited.end())
                {
                    this->has_cicle_directed(i, visited, current_path, hasCycle);
                    if (hasCycle)
                    {
                        return true;
                    }
                }
            }
        }
        //*******____graph is undirected____*******//
        else
        {
            for (std::size_t i = 0; i < m_AdjacencyList.size(); ++i)
            {
                if (visited.find(i) == visited.end())
                {
                    this->has_cicle_undirected(i, std::numeric_limits<std::size_t>::max(), visited, hasCycle);
                    {
                        if (hasCycle)
                        {
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }

    //---------------------------has_cicle_undirected--------------------------//
    std::vector<std::size_t> Graph::Topological_sort()
    {
        if (!m_is_directed)
        {
            throw std::logic_error("undirected graph cannot have a topological sort");
        }

        std::vector<int>         inDegree(m_AdjacencyList.size(), 0);
        std::vector<std::size_t> res;
        res.reserve(m_AdjacencyList.size());

        for (std::size_t U = 0; U < m_AdjacencyList.size(); ++U)
        {
            for (const auto Vert : m_AdjacencyList[U])
            {
                ++inDegree[Vert];
            }
        }

        std::queue<std::size_t> queu;

        for (std::size_t i = 0; i < m_AdjacencyList.size(); ++i)
        {
            if (inDegree[i] == 0)
            {
                queu.push(i);
            }
        }

        while (!queu.empty())
        {
            std::size_t node = queu.front();
            queu.pop();
            res.push_back(node);
            for (const auto elem : m_AdjacencyList[node])
            {
                --inDegree[elem];
                if (inDegree[elem] == 0)
                {
                    queu.push(elem);
                }
            }
        }

        if (res.size() == m_AdjacencyList.size())
        {
            for (const auto elem : res)
            {
                std::cout << elem << " ";
            }

            std::cout << std::endl;
            return res;
        }

        throw std::logic_error("the graph hes loop can't do Topological_sort\n");
    }

    //---------------------------has_cicle_undirected--------------------------//
    void Graph::has_cicle_undirected(std::size_t vert, std::size_t parent, std::unordered_set<std::size_t> visited,
                                     bool& has_sycle)
    {
        visited.insert(vert);

        for (const auto neighbor : m_AdjacencyList[vert])
        {
            if (visited.find(neighbor) == visited.end())
            {
                has_cicle_undirected(neighbor, vert, visited, has_sycle);
            }
            else if (neighbor != parent)
            {
                has_sycle = true;
                return;
            }
        }
    }

    //---------------------------has_cicle_directed--------------------------//
    void Graph::has_cicle_directed(std::size_t vert, std::unordered_set<std::size_t>& visited,
                                   std::unordered_set<std::size_t>& current_path, bool& hasCycle)
    {
        visited.insert(vert);
        current_path.insert(vert);

        for (auto neighbor : m_AdjacencyList[vert])
        {
            if (current_path.find(neighbor) != current_path.end())
            {
                hasCycle = true;
                return;
            }

            if (visited.find(neighbor) == visited.end())
            {
                has_cicle_directed(neighbor, visited, current_path, hasCycle);
            }
        }

        current_path.erase(vert);
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
