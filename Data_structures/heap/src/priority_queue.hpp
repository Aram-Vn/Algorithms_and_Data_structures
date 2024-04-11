template <typename T, typename Cmp>
my::priority_queue<T, Cmp>::priority_queue(container_type& input)
    : m_heap(input),
      m_size(input.size()),
      m_cmp(Cmp{})
{
    make_heap();
}

template <typename T, typename Cmp>
my::priority_queue<T, Cmp>::priority_queue()
    : m_heap{},
      m_size(0),
      m_cmp(Cmp{})
{
}

template <typename T, typename Cmp>
template <typename RandomAccessIterator>
my::priority_queue<T, Cmp>::priority_queue(RandomAccessIterator first, RandomAccessIterator last)
    : m_heap(first, last),
      m_size(last - first),
      m_cmp()
{
    make_heap();
}

template <typename T, typename Cmp>
void my::priority_queue<T, Cmp>::make_heap()
{
    for (int i = (m_size / 2) - 1; i >= 0; --i)
    {
        heapify_down(i);
    }
}

template <typename T, typename Cmp>
size_t priority_queue<T, Cmp>::parent(size_t ind)
{
    return (ind - 1) / 2;
}

template <typename T, typename Cmp>
size_t my::priority_queue<T, Cmp>::left(size_t ind)
{
    return 2 * ind + 1;
}

template <typename T, typename Cmp>
size_t my::priority_queue<T, Cmp>::right(size_t ind)
{
    return 2 * ind + 2;
}

template <typename T, typename Cmp>
void my::priority_queue<T, Cmp>::heapify_down(size_t ind)
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
void my::priority_queue<T, Cmp>::push(const_reference val)
{
    m_heap.push_back(val);
    ++m_size;

    size_t index = m_size - 1;
    while (index > 0 && m_cmp(val, m_heap[parent(index)]))
    {
        std::swap(m_heap[index], m_heap[parent(index)]);
        index = parent(index);
    }
}

template <typename T, typename Cmp>
void my::priority_queue<T, Cmp>::pop()
{
    if (m_size == 0)
    {
        return;
    }

    std::swap(m_heap[0], m_heap[m_size - 1]);
    m_heap.pop_back();
    --m_size;

    heapify_down(0);
}

template <typename T, typename Cmp>
typename my::priority_queue<T, Cmp>::const_reference my::priority_queue<T, Cmp>::top()
{
    if (m_size == 0)
    {
        throw std::out_of_range("priority_queue is empty");
    }

    return m_heap[0];
}

template <typename T, typename Cmp>
bool my::priority_queue<T, Cmp>::empty()
{
    return m_size == 0;
}

template <typename T, typename Cmp>
typename my::priority_queue<T, Cmp>::size_type my::priority_queue<T, Cmp>::size()
{
    return m_size;
}

template <typename T, typename Cmp>
void my::priority_queue<T, Cmp>::print()
{
    for (int i = 0; i < m_size; ++i)
    {
        std::cout << m_heap[i] << " ";
    }
    std::cout << std::endl;
}
