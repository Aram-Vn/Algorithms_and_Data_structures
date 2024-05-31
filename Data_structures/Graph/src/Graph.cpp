#include "../headers/Graph.h"
#include <cstddef>
#include <string>

namespace my {

    Graph::Graph(std::size_t vertex_amount, bool is_directed, bool create)
        : m_AdjacencyList(vertex_amount, std::vector<std::size_t>()),
          m_is_directed(is_directed)
    {
        if (create)
        {
            for (std::size_t i = 0; i < vertex_amount; ++i)
            {
                while (true)
                {
                    std::cout << i << "-> ";

                    std::vector<std::size_t> vertices = get_vertices_input();
                    if (vertices.empty())
                    {
                        break;
                    }

                    for (std::size_t to_vertex : vertices)
                    {
                        if (to_vertex < m_AdjacencyList.size())
                        {
                            add_edge(i, to_vertex);
                        }
                        else
                        {
                            std::cout << "Invalid vertex " << to_vertex << ". Please enter values between 0 and "
                                      << m_AdjacencyList.size() - 1 << " or # to stop.\n";
                        }
                    }
                }
            }
        }
    }

    std::vector<std::size_t> Graph::get_vertices_input() const
    {
        std::string input;
        std::getline(std::cin, input);

        if (input == "#")
        {
            return {};
        }

        std::istringstream       iss(input);
        std::vector<std::size_t> vertices;
        std::size_t              vertex;
        while (iss >> vertex)
        {
            vertices.push_back(vertex);
        }

        if (iss.fail() && !iss.eof())
        {
            std::cout << "Invalid input. Please enter valid numbers separated by spaces or # to stop.\n";
            return get_vertices_input();
        }

        return vertices;
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
    void Graph::dfs_rec(std::size_t vert, bool print_preorder)
    {
        std::vector<bool> visited(m_AdjacencyList.size(), false);

        std::function<void(std::size_t vert)> dfs_lambda = [this, &dfs_lambda, &visited, print_preorder](
                                                               std::size_t vertex) -> void
        {
            visited[vertex] = true;
            if (print_preorder)
            {
                std::cout << vertex << " "; // preorder
            }

            for (const auto u_vert : m_AdjacencyList[vertex])
            {
                if (!visited[u_vert])
                {
                    dfs_lambda(u_vert);
                }
            }
            if (!print_preorder)
            {
                std::cout << vertex << " "; // postorder
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

    //---------------------------_-has_cycle-_--------------------------//
    bool Graph::has_cycle()
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
                    this->has_cycle_directed(i, visited, current_path, hasCycle);
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
                    this->has_cycle_undirected(i, std::numeric_limits<std::size_t>::max(), visited, hasCycle);
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

    //---------------------------Topological_sort--------------------------//
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

        std::queue<std::size_t> queue;

        for (std::size_t i = 0; i < m_AdjacencyList.size(); ++i)
        {
            if (inDegree[i] == 0)
            {
                queue.push(i);
            }
        }

        while (!queue.empty())
        {
            std::size_t node = queue.front();
            queue.pop();
            res.push_back(node);
            for (const auto elem : m_AdjacencyList[node])
            {
                --inDegree[elem];
                if (inDegree[elem] == 0)
                {
                    queue.push(elem);
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

    //---------------------------has_cycle_undirected--------------------------//
    void Graph::has_cycle_undirected(std::size_t vert, std::size_t parent, std::unordered_set<std::size_t> visited,
                                     bool& has_sycl)
    {
        visited.insert(vert);

        for (const auto neighbor : m_AdjacencyList[vert])
        {
            if (visited.find(neighbor) == visited.end())
            {
                has_cycle_undirected(neighbor, vert, visited, has_sycl);
            }
            else if (neighbor != parent)
            {
                has_sycl = true;
                return;
            }
        }
    }

    //---------------------------has_cycle_directed--------------------------//
    void Graph::has_cycle_directed(std::size_t vert, std::unordered_set<std::size_t>& visited,
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
                has_cycle_directed(neighbor, visited, current_path, hasCycle);
            }
        }

        current_path.erase(vert);
    }

    // //---------------------------_ptims_MST_--------------------------//
    // long Graph::ptims_MST(vertex_t start_vert) const
    // {
    //     std::vector<bool> visited(m_AdjacencyList.size(), false);
    //     long              res = 0;

    //     using dist_vert_Pair = std::pair<inf_t, vertex_t>;

    //     auto cmp = [](const auto& pair1, const auto& pair2) -> bool { return pair1.first > pair2.first; };

    //     std::priority_queue<dist_vert_Pair, std::vector<dist_vert_Pair>, decltype(cmp)> pq(cmp);
    //     pq.emplace(0, start_vert);

    //     while (!pq.empty())
    //     {
    //         auto [u, cost] = pq.top();
    //         pq.pop();
    //         visited[(std::size_t)u] = true;
    //         res += cost;

    //         for (const auto& [v, w] : m_AdjacencyList[u])
    //         {

    //         }
    //     }

    //     return res;
    // }

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
