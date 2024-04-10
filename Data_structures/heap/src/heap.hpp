template <typename T, typename Cmp>
my::Heap<T, Cmp>::Heap(std::vector<T> &input, const Cmp &cmp)
    : m_heap(input),
      m_size(input.size()),
      m_cmp(cmp)
{
    make_heap();
}

template <typename T, typename Cmp>
template <typename RandomAccessIterator>
my::Heap<T, Cmp>::Heap(RandomAccessIterator first, RandomAccessIterator last)
    : m_heap(first, last),
      m_size(last - first),
      m_cmp()
{
    make_heap();
}

template <typename T, typename Cmp>
void my::Heap<T, Cmp>::make_heap()
{
    for (int i = (m_size / 2) - 1; i >= 0; --i)
    {
        heapify_down(i);
    }
}

template <typename T, typename Cmp>
size_t Heap<T, Cmp>::parent(size_t ind)
{
    return (ind - 1) / 2;
}

template <typename T, typename Cmp>
size_t my::Heap<T, Cmp>::left(size_t ind)
{
    return 2 * ind + 1;
}

template <typename T, typename Cmp>
size_t my::Heap<T, Cmp>::right(size_t ind)
{
    return 2 * ind + 2;
}

template <typename T, typename Cmp>
void my::Heap<T, Cmp>::heapify_down(size_t ind)
{
    size_t largest = ind;
    size_t l       = left(ind);
    size_t r       = right(ind);

    if (l < m_size && m_cmp(m_heap[l], m_heap[largest]))
        largest = l;

    if (r < m_size && m_cmp(m_heap[r], m_heap[largest]))
        largest = r;

    if (largest != ind)
    {
        std::swap(m_heap[ind], m_heap[largest]);
        heapify_down(largest);
    }
}

template <typename T, typename Cmp>
void my::Heap<T, Cmp>::print()
{
    for (int i = 0; i < m_size; ++i)
    {
        std::cout << m_heap[i] << " ";
    }
    std::cout << std::endl;
}
