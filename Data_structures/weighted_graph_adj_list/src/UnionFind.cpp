#include "../include/UnionFind.h"
#include <cstddef>

namespace util {

    UnionFind::UnionFind(std::size_t size_)
        : m_parent(size_),
          m_size(size_, 1)
    {
        std::iota(m_parent.begin(), m_parent.end(), 0);
    }

    UnionFind::vertex_t UnionFind::find(vertex_t vert)
    {
        if (vert == m_parent[vert])
        {
            return vert;
        }
        else
        {
            return m_parent[vert] = find(m_parent[vert]); // path compression
        }
    }

    void UnionFind::unify(vertex_t U_vert, vertex_t V_vert)
    {
        U_vert = find(U_vert);
        V_vert = find(V_vert);

        if (U_vert != V_vert) // Only unify if they are in different sets
        {
            if (m_size[U_vert] > m_size[V_vert])
            {
                m_parent[V_vert] = U_vert;
                m_size[U_vert] += m_size[V_vert];
            }
            else
            {
                m_parent[U_vert] = V_vert;
                m_size[V_vert] += m_size[U_vert];
            }
        }
    }

} // namespace util