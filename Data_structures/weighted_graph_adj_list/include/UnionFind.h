#ifndef WEIGHTED_GRAPH_ADJ_LIST_INCLUDE_UNIONFIND_H
#define WEIGHTED_GRAPH_ADJ_LIST_INCLUDE_UNIONFIND_H

#include <cstddef>
#include <cstdint>
#include <numeric>
#include <vector>

namespace util {
    class UnionFind
    {
    public:
        using vertex_t = std::size_t;

    public:
        explicit UnionFind(std::size_t size_);

    public:
        vertex_t find(vertex_t vert);
        bool     unify(vertex_t U_vert, vertex_t V_vert);

    private:
        std::vector<vertex_t>    m_parent;
        std::vector<std::size_t> m_size;
    };

} // namespace util

#endif // WEIGHTED_GRAPH_ADJ_LIST_INCLUDE_UNIONFIND_H