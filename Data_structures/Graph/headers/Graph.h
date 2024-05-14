#ifndef DATA_STRUCTURES_GRAPH_HEADERS_GRAPH_H
#define DATA_STRUCTURES_GRAPH_HEADERS_GRAPH_H

#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <stack>
#include <stdexcept>
#include <unordered_set>
#include <vector>

namespace my {
    class Graph
    {
    public:
        Graph(std::size_t x, bool is_directed = true); //
        ~Graph(){};                                    //

    public:
        void add_vertex();                                          //
        void add_edge(std::size_t vertex1, std::size_t vertex2);    //
        void remove_edge(std::size_t vertex1, std::size_t vertex2); //

        bool has_cicle();

        void dfs_rec(std::size_t vert, bool flag = true); //
        void dfs_iter(std::size_t vert);                  //

        void                     bfs(std::size_t start_vertex); //
        std::vector<std::size_t> Topological_sort();

        void print() const; //

    private:
        void has_cicle_undirected(std::size_t vert, std::size_t parent, std::unordered_set<std::size_t>,
                                  bool& has_sycle);
        void has_cicle_directed(std::size_t vert, std::unordered_set<std::size_t>& visited,
                                std::unordered_set<std::size_t>& current_path, bool& hasCycle);

    private:
        std::vector<std::vector<std::size_t>> m_AdjacencyList;
        bool                                  m_is_directed;
    };
} // namespace my

#endif // DATA_STRUCTURES_GRAPH_HEADERS_GRAPH_H
