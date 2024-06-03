
#include "../include/weighted_graph_adj_list.h"
#include <queue>
#include <stdexcept>
#include <tuple>
#include <vector>

namespace my {
    weighted_graph::weighted_graph(std::size_t size, bool is_directed)
        : m_graph(size),
          m_is_directed(is_directed)
    {
    }

    //-------------------------_add_vertex_---------------------//
    void weighted_graph::add_vertex()
    {
        m_graph.emplace_back();
    }

    //--------------------------_add_edge_-----------------------//
    void weighted_graph::add_edge(const vertex_t src_vertex1, const vertex_t vertex2, const weight_t weight)
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

        if (m_is_directed)
        {
            std::vector<Edge>& edges = m_graph[src_vertex1];

            // check if the edge already exists
            auto it = std::find_if(edges.begin(), edges.end(), [vertex2](const Edge& edge) {
                return edge.first == vertex2;
            });

            if (it == edges.end()) // if no edge add it
            {
                m_graph[src_vertex1].emplace_back(vertex2, weight);
            }
            else // if edge exists change weight
            {
                it->second = weight;
            }
        }
        else
        {
            // Add edge from src_vertex1 to vertex2
            std::vector<Edge>& edges_from_src = m_graph[src_vertex1];

            auto it_src = std::find_if(edges_from_src.begin(), edges_from_src.end(), [vertex2](const Edge& edge) {
                return edge.first == vertex2;
            });

            if (it_src == edges_from_src.end()) // if no edge add it
            {
                m_graph[src_vertex1].emplace_back(vertex2, weight);
            }
            else // if edge exists change weight
            {
                it_src->second = weight;
            }

            // Add edge from vertex2 to src_vertex1
            std::vector<Edge>& edges_from_vertex2 = m_graph[vertex2];

            auto it_vertex2 =
                std::find_if(edges_from_vertex2.begin(), edges_from_vertex2.end(), [src_vertex1](const Edge& edge) {
                    return edge.first == src_vertex1;
                });

            if (it_vertex2 == edges_from_vertex2.end()) // if no edge add it
            {
                m_graph[vertex2].emplace_back(src_vertex1, weight);
            }
            else // if edge exists change weight
            {
                it_vertex2->second = weight;
            }
        }
    }

    //-----------------------------_-dfs_rec-_----------------------//
    void weighted_graph::dfs(const vertex_t start_vert, bool print_preorder) const
    {
        std::vector<bool> visited(m_graph.size(), false);

        dfs(start_vert, visited, print_preorder);

        for (vertex_t i = 0; i < m_graph.size(); ++i)
        {
            if (visited[i] == false)
            {
                dfs(i, visited, print_preorder);
            }
        }

        std::cout << std::endl;
    }

    void weighted_graph::dfs(vertex_t src, std::vector<bool>& visited, bool print_preorder) const
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
    void weighted_graph::bfs(const vertex_t start_vert) const
    {
        std::vector<bool> visited(m_graph.size(), false);

        bfs(start_vert, visited);

        for (vertex_t vertex = 0; vertex < m_graph.size(); ++vertex)
        {
            if (!visited[vertex])
            {
                bfs(vertex, visited);
            }
        }
        std::cout << std::endl;
    }

    void weighted_graph::bfs(vertex_t start_vertex, std::vector<bool>& visited) const
    {
        std::queue<vertex_t> qu;

        qu.push(start_vertex);
        visited[start_vertex] = true;

        while (!qu.empty())
        {
            vertex_t current_vert = qu.front();
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

    /*---------------------------------------------------------------------*/
    /*---------------------------*_kosaraju_scc_*--------------------------*/
    /*---------------------------------------------------------------------*/
    void weighted_graph::kosaraju_scc() const
    {
        if (!m_is_directed)
        {
            throw std::logic_error("cant find SCCs in underacted graph");
        }

        std::cout << "kosaraju_scc: " << std::endl;

        std::stack<vertex_t> finish_stack;
        std::vector<bool>    visited(m_graph.size(), false);

        // Step 1: Perform DFS and push vertices to finish_stack
        for (vertex_t i = 0; i < m_graph.size(); ++i)
        {
            if (!visited[i])
            {
                dfs_kosaraju(i, visited, finish_stack);
            }
        }

        // Step 2: Transpose the graph
        AdjacencyList transposed_graph = this->transpose();

        std::fill(visited.begin(), visited.end(), false);

        // Step 3: Perform DFS on the transposed graph
        while (!finish_stack.empty())
        {
            vertex_t v = finish_stack.top();
            finish_stack.pop();

            if (!visited[v])
            {
                std::vector<vertex_t> component;
                dfs_transposed(v, transposed_graph, visited, component);

                // Output the current SCC
                std::cout << "SCC: ";
                for (vertex_t vert : component)
                {
                    std::cout << vert << " ";
                }
                std::cout << "\n";
            }
        }
    }

    //---------------------------_transpose_--------------------------//
    weighted_graph::AdjacencyList weighted_graph::transpose() const
    {
        AdjacencyList transposed(m_graph.size());

        for (vertex_t v = 0; v < m_graph.size(); ++v)
        {
            for (const auto& neighbor : m_graph[v])
            {
                transposed[neighbor.first].emplace_back(v, neighbor.second);
            }
        }

        return transposed;
    }

    //---------------------------_dfs_kosaraju_--------------------------//
    void weighted_graph::dfs_kosaraju(vertex_t vertex, std::vector<bool>& visited,
                                      std::stack<vertex_t>& finish_stack) const
    {
        visited[vertex] = true;

        for (const auto& neighbor : m_graph[vertex])
        {
            if (!visited[neighbor.first])
            {
                dfs_kosaraju(neighbor.first, visited, finish_stack);
            }
        }

        finish_stack.push(vertex);
    }

    //---------------------------_dfs_transposed_--------------------------//
    void weighted_graph::dfs_transposed(vertex_t vertex, const AdjacencyList& transposed_graph,
                                        std::vector<bool>& visited, std::vector<vertex_t>& component) const
    {
        visited[vertex] = true;
        component.push_back(vertex);
        for (const auto& neighbor : transposed_graph[vertex])
        {
            if (!visited[neighbor.first])
            {
                dfs_transposed(neighbor.first, transposed_graph, visited, component);
            }
        }
    }

    /*---------------------------------------------------------------------*/
    /*----------------------------*_TARJAN_SCC_-*--------------------------*/
    /*---------------------------------------------------------------------*/
    void weighted_graph::tarjan_scc() const
    {
        if (!m_is_directed)
        {
            throw std::logic_error("cant find SCCs in underacted graph");
        }

        std::vector<long>                  ids(m_graph.size(), -1);
        std::vector<long>                  low(m_graph.size(), -1);
        std::vector<bool>                  on_stack(m_graph.size(), false);
        std::stack<vertex_t>               stack;
        std::vector<std::vector<vertex_t>> sccs;
        vertex_t                           id = 0;

        for (vertex_t vertex = 0; vertex < m_graph.size(); ++vertex)
        {
            if (ids[vertex] == -1)
            {
                tarjan_scc_util(vertex, ids, low, on_stack, stack, sccs, id);
            }
        }

        std::cout << "tarjan_scc: " << std::endl;

        for (const auto& scc : sccs)
        {
            std::cout << "SCC: ";
            for (vertex_t vertex : scc)
            {
                std::cout << vertex << " ";
            }
            std::cout << std::endl;
        }
    }

    void weighted_graph::tarjan_scc_util(vertex_t vertex, std::vector<long>& ids, std::vector<long>& low,
                                         std::vector<bool>& on_stack, std::stack<vertex_t>& stack,
                                         std::vector<std::vector<vertex_t>>& sccs, vertex_t& id) const
    {
        ids[vertex] = low[vertex] = static_cast<long>(id++);
        stack.push(vertex);
        on_stack[vertex] = true;

        for (const auto& neighbor : m_graph[vertex])
        {
            vertex_t next_vertex = neighbor.first;

            if (ids[next_vertex] == -1)
            {
                tarjan_scc_util(next_vertex, ids, low, on_stack, stack, sccs, id);
            }

            if (on_stack[next_vertex])
            {
                low[vertex] = std::min(low[vertex], low[next_vertex]);
            }
        }

        if (ids[vertex] == low[vertex])
        {
            std::vector<vertex_t> scc;
            vertex_t              top_vertex;

            do
            {
                top_vertex = stack.top();
                stack.pop();
                on_stack[top_vertex] = false;
                scc.push_back(top_vertex);

            } while (top_vertex != vertex);

            sccs.push_back(scc);
        }
    }

    //---------------------------_topological_sort_--------------------------//
    std::stack<weighted_graph::vertex_t> weighted_graph::topological_sort() const
    {
        std::stack<vertex_t> Stack;
        std::vector<bool>    visited(m_graph.size(), false);
        std::vector<bool>    rec_stack(m_graph.size(), false);

        for (vertex_t i = 0; i < m_graph.size(); ++i)
        {
            if (!visited[i])
            {
                if (topological_sort_util(i, visited, rec_stack, Stack))
                {
                    throw std::runtime_error("Graph contains a cycle\ncant do topological_sort");
                }
            }
        }

        return Stack;
    }

    bool weighted_graph::topological_sort_util(vertex_t cur_vert, std::vector<bool>& visited,
                                               std::vector<bool>& rec_stack, std::stack<vertex_t>& Stack) const
    {
        visited[cur_vert]   = true;
        rec_stack[cur_vert] = true;

        for (const auto& [neighbor, weight] : m_graph[cur_vert])
        {
            if (!visited[neighbor] && topological_sort_util(neighbor, visited, rec_stack, Stack))
            {
                return true;
            }
            else if (rec_stack[neighbor])
            {
                return true;
            }
        }

        rec_stack[cur_vert] = false;
        Stack.push(cur_vert);
        return false;
    }
    //---------------------------_dag_SSSP_top_sort_--------------------------//
    void weighted_graph::dag_SSSP_top_sort(vertex_t start_vertex, std::vector<inf_t>& distances) const
    {
        if (!m_is_directed)
        {
            throw std::logic_error("cant do SSSP using top_sort in underacted graph");
        }

        std::stack<vertex_t> Stack = topological_sort();

        distances.assign(m_graph.size(), INF);
        distances[start_vertex] = 0;

        while (!Stack.empty())
        {
            vertex_t cur_vert = Stack.top();
            Stack.pop();

            if (distances[cur_vert] != INF)
            {
                for (const auto& [neighbor, neighbor_weight] : m_graph[cur_vert])
                {
                    inf_t new_dist;
                    if (__builtin_add_overflow(distances[cur_vert], neighbor_weight, &new_dist))
                    {
                        new_dist = INF; // of there is overflow set new_dist as INF
                    }

                    if (distances[neighbor] > new_dist)
                    {
                        distances[neighbor] = new_dist;
                    }
                }
            }
        }

        this->print_paths(start_vertex, distances);
    }

    //---------------------------_dijkstra_--------------------------//
    void weighted_graph::dijkstra(const vertex_t start_vert, std::vector<inf_t>& res) const
    {
        std::vector<inf_t> distances(m_graph.size(), INF);
        distances[start_vert] = 0;

        using dist_vert_Pair = std::pair<inf_t, vertex_t>;

        auto cmp = [](const auto& pair1, const auto& pair2) -> bool {
            return pair1.first > pair2.first;
        };

        std::priority_queue<dist_vert_Pair, std::vector<dist_vert_Pair>, decltype(cmp)> pq(cmp);

        pq.emplace(0, start_vert); // Distance to the start vertex itself is 0

        while (!pq.empty())
        {
            // Get the vertex with the smallest distance
            auto [current_dist, current_vertex] = pq.top();
            pq.pop();

            if (current_dist > distances[current_vertex])
            {
                continue; // If the current distance is greater than the recorded distance, skip processing
            }

            // Iterate through all neighbors of the current vertex
            for (const auto& [neighbor, neighbor_weight] : m_graph[current_vertex])
            {
                if (neighbor_weight < 0)
                {
                    throw std::runtime_error("Graph contains a negative weight edge.");
                }

                // overflow guard
                // Calculate the new distance = neighbor_weight + current_dist
                inf_t new_dist;
                if (__builtin_add_overflow(current_dist, neighbor_weight, &new_dist))
                {
                    new_dist = INF; // of there is overflow set new_dist as INF
                }

                if (new_dist < distances[neighbor])
                {
                    // If the new distance is shorter, update it and push it to the priority queue
                    distances[neighbor] = new_dist;
                    pq.emplace(new_dist, neighbor);
                }
            }
        }

        res.assign(m_graph.size(), INF);
        for (size_t i = 0; i < distances.size(); ++i)
        {
            if (distances[i] != INF)
            {
                res[i] = distances[i];
            }
        }

        this->print_paths(start_vert, res);
    }

    //---------------------------_bellman_ford_--------------------------//
    bool weighted_graph::bellman_ford(vertex_t start_vertex, std::vector<inf_t>& distances) const
    {
        distances.assign(m_graph.size(), INF);
        distances[start_vertex] = 0;

        for (std::size_t i = 1; i < m_graph.size(); ++i) // Relax all edges |V| - 1 times
        {
            for (vertex_t current_vert = 0; current_vert < m_graph.size(); ++current_vert)
            {
                for (const auto& [neighbor, neighbor_weight] : m_graph[current_vert])
                {
                    if (distances[current_vert] != INF &&
                        distances[neighbor] > distances[current_vert] + neighbor_weight)
                    {
                        // If the cur distance is not INF and the new calculated distance is shorter, updating it
                        distances[neighbor] = distances[current_vert] + neighbor_weight;
                    }
                }
            }
        }

        bool no_neg_cycle = true;

        // Check for negative weight cycles
        for (std::size_t i = 0; i < m_graph.size(); ++i)
        {
            for (vertex_t current_vertex = 0; current_vertex < m_graph.size(); ++current_vertex)
            {
                if (distances[current_vertex] == INF)
                {
                    continue;
                }

                for (const auto& [neighbor, neighbor_weight] : m_graph[current_vertex])
                {
                    // overflow guard
                    inf_t new_dist;
                    if (__builtin_add_overflow(distances[current_vertex], neighbor_weight, &new_dist))
                    {
                        new_dist = -INF; // if there is overflow set new_dist as -INF
                    }

                    if (distances[neighbor] > new_dist)
                    {
                        no_neg_cycle        = false;
                        distances[neighbor] = -INF;
                    }
                }
            }
        }

        this->print_paths(start_vertex, distances);

        return no_neg_cycle;
    }

    //---------------------------_print_paths_--------------------------//
    long weighted_graph::ptims_MST(vertex_t start_vert) const
    {
        if (m_is_directed)
        {
            throw std::logic_error("cant do ptims_MST on directed graph");
        }

        long               total_weight = 0;               // Total weight of the minimum spanning tree
        std::vector<bool>  visited(m_graph.size(), false); // Tracks vertices included in MST
        std::vector<inf_t> key(m_graph.size(), INF);       // Tracks the minimum edge
        // std::vector<vertex_t> MST(m_graph.size());            // Track MST edges

        auto cmp = [](const auto& pair1, const auto& pair2) -> bool {
            return pair1.first > pair2.first;
        };

        using dist_vert_Pair = std::pair<inf_t, vertex_t>;

        std::priority_queue<dist_vert_Pair, std::vector<dist_vert_Pair>, decltype(cmp)> pq(cmp);

        key[start_vert] = 0;
        pq.emplace(0, start_vert);

        while (!pq.empty())
        {
            vertex_t current_vertex = pq.top().second;
            pq.pop();

            if (visited[current_vertex]) // If the vertex is already in MST, continue to the next iteration
            {
                continue;
            }

            visited[current_vertex] = true;
            total_weight += key[current_vertex]; // Add the weight of the edge connecting the
                                                 // current vertex to the MST

            for (const auto& [neighbor, neighb_weight] : m_graph[current_vertex])
            {
                if (!visited[neighbor] && neighb_weight < key[neighbor])
                {
                    // Update the minimum edge weight to connect the adjacent vertex to the MST
                    key[neighbor] = neighb_weight;
                    pq.emplace(key[neighbor], neighbor);

                    // Add the edge to the MST
                    // MST[current_vertex] = neighbor;
                }
            }
        }

        // print_MST(MST); // Print MST
        return total_weight;
    }

    //---------------------------_kruskal_MST_--------------------------//
    long weighted_graph::kruskal_MST() const
    {
        if (m_is_directed)
        {
            throw std::logic_error("Cannot perform Kruskal's algorithm on a directed graph");
        }

        long                                       total_weight = 0;
        std::vector<std::pair<vertex_t, vertex_t>> mst_edges;
        using Edge_tuple = std::tuple<weight_t, vertex_t, vertex_t>;

        auto cmp = [](const Edge_tuple& edge1, const Edge_tuple& edge2) -> bool {
            return std::get<0>(edge1) > std::get<0>(edge2);
        };

        std::priority_queue<Edge_tuple, std::vector<Edge_tuple>, decltype(cmp)> pq(cmp);

        for (vertex_t U_vert = 0; U_vert < m_graph.size(); ++U_vert)
        {
            for (const auto& [V_vert, weight] : m_graph[U_vert])
            {
                if (U_vert < V_vert) // only uniques
                {
                    pq.emplace(weight, U_vert, V_vert);
                }
            }
        }

        util::UnionFind uf(m_graph.size());

        while (!pq.empty())
        {
            auto [weight, U_vert, V_vert] = pq.top();
            pq.pop();

            if (uf.find(U_vert) != uf.find(V_vert))
            {
                uf.unify(U_vert, V_vert);
                total_weight += weight;
                mst_edges.emplace_back(U_vert, V_vert);
            }
        }

        this->print_MST(mst_edges);

        return total_weight;
    }

    //---------------------------_print_MST_--------------------------//
    void weighted_graph::print_MST(const std::vector<std::pair<vertex_t, vertex_t>>& mst_edges) const
    {
        // Print the edges of the MST
        std::cout << "Minimum Spanning Tree (MST) Edges:\n";
        for (const auto& [u, v] : mst_edges)
        {
            std::cout << u << " - " << v << "\n";
        }
    }

    //---------------------------_print_paths_--------------------------//
    void weighted_graph::print_paths(vertex_t start_vert, const std::vector<inf_t>& distances) const
    {
        vertex_t dest_vert = 0;

        for (inf_t weight : distances)
        {
            if (weight == INF)
            {
                ++dest_vert;
                continue;
            }
            else if (weight == -INF)
            {
                std::cout << "shortest path from  " << start_vert << "  to  " << dest_vert << " Is affected \n";
                ++dest_vert;
                continue;
            }

            std::cout << "shortest path from  " << start_vert << "  to  " << dest_vert << "  is  " << weight;
            ++dest_vert;
            std::cout << std::endl;
        }
    }

    //---------------------------_print_--------------------------//
    void weighted_graph::print() const
    {
        for (std::size_t i = 0; i < m_graph.size(); ++i)
        {
            std::cout << i << " -> ";

            for (const auto& elem : m_graph[i])
            {
                std::cout << "e:" << elem.first << " w:" << elem.second << " | ";
            }
            std::cout << std::endl;
        }
    }

} // namespace my
