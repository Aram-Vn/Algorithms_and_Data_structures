template <typename T, typename Cmp,  typename Container>
my::priority_queue<T, Cmp, Container>::priority_queue(const container_type& input)
    : m_heap(input),
      m_size(input.size()),
      m_cmp(Cmp{})
{
    make_heap();
}

template <typename T, typename Cmp,  typename Container>
my::priority_queue<T, Cmp, Container>::priority_queue()
    : m_heap{},
      m_size(0),
      m_cmp(Cmp{})
{
}

template <typename T, typename Cmp,  typename Container>
template <typename RandomAccessIterator>
my::priority_queue<T, Cmp, Container>::priority_queue(RandomAccessIterator first, RandomAccessIterator last)
    : m_heap(first, last),
      m_size(last - first),
      m_cmp()
{
    make_heap();
}

//-----------------------------_-make_heap-_-------------------------------//
template <typename T, typename Cmp,  typename Container>
void my::priority_queue<T, Cmp, Container>::make_heap()
{
    for (int i = (m_size / 2) - 1; i >= 0; --i)
    {
        heapify_down(i);
    }
}

//-----------------------------_-parent-_-------------------------------//

template <typename T, typename Cmp, typename Container>
constexpr size_t priority_queue<T, Cmp, Container>::parent(const size_t ind) const noexcept
{
    return (ind - 1) / 2;
}

//-----------------------------_-left-_-------------------------------//
template <typename T, typename Cmp,  typename Container>
constexpr size_t my::priority_queue<T, Cmp, Container>::left(const size_t ind) const noexcept
{
    return 2 * ind + 1;
}

//-----------------------------_-right-_-------------------------------//
template <typename T, typename Cmp,  typename Container>
constexpr size_t my::priority_queue<T, Cmp, Container>::right(const size_t ind) const noexcept
{
    return 2 * ind + 2;
}

//-----------------------------_-heapify_down-_-------------------------------//
template <typename T, typename Cmp,  typename Container>
void my::priority_queue<T, Cmp, Container>::heapify_down(const size_t ind)
{
    size_t largest   = ind;
    size_t leftNode  = left(ind);
    size_t rightNode = right(ind);

    if (leftNode < m_size && m_cmp(m_heap[leftNode], m_heap[largest]))
        largest = leftNode;

    if (rightNode < m_size && m_cmp(m_heap[rightNode], m_heap[largest]))
        largest = rightNode;

    if (largest != ind)
    {
        std::swap(m_heap[ind], m_heap[largest]);
        heapify_down(largest);
    }
}

//-----------------------------_-push-_-------------------------------//
template <typename T, typename Cmp,  typename Container>
void my::priority_queue<T, Cmp, Container>::push(const_reference val)
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

//-----------------------------_-pop-_-------------------------------//
template <typename T, typename Cmp,  typename Container>
void my::priority_queue<T, Cmp, Container>::pop()
{
    if (m_size == 0)
    {
        return;
    }

    std::swap(m_heap[0], m_heap[m_size - 1]);
    m_heap.pop_back();
    --m_size;

    heapify_down(0); // Restore the heap property
}

//-----------------------------_-extract_top-_-------------------------------//
template <typename T, typename Cmp,  typename Container>
typename my::priority_queue<T, Cmp, Container>::value_type my::priority_queue<T, Cmp, Container>::extract_top()
{
    if (m_size == 0)
    {
        throw std::out_of_range("priority_queue is empty");
    }

    value_type top_value = m_heap[0];

    std::swap(m_heap[0], m_heap[m_size - 1]);
    m_heap.pop_back();
    --m_size;

    heapify_down(0); // Restore the heap property

    return top_value;
}

//-----------------------------_-top-_-------------------------------//
template <typename T, typename Cmp,  typename Container>
constexpr typename my::priority_queue<T, Cmp, Container>::const_reference my::priority_queue<T, Cmp, Container>::top() const
{
    if (m_size == 0)
    {
        throw std::out_of_range("priority_queue is empty");
    }

    return m_heap[0];
}

//-----------------------------_-empty-_-------------------------------//
template <typename T, typename Cmp,  typename Container>
constexpr bool my::priority_queue<T, Cmp, Container>::empty() const noexcept
{
    return m_size == 0;
}

//-----------------------------_-size-_-------------------------------//
template <typename T, typename Cmp,  typename Container>
constexpr typename my::priority_queue<T, Cmp, Container>::size_type my::priority_queue<T, Cmp, Container>::size() const noexcept
{
    return m_size;
}

//-----------------------------_-print-_-------------------------------//
template <typename T, typename Cmp,  typename Container>
void my::priority_queue<T, Cmp, Container>::print() const noexcept
{
    if (m_heap.empty())
    {
        std::cout << "Priority queue is empty." << std::endl;
        return;
    }

    for (int i = 0; i < m_size; ++i)
    {
        std::cout << m_heap[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T, typename Cmp,  typename Container>
void my::priority_queue<T, Cmp, Container>::print_level() const noexcept
{
    if (m_heap.empty())
    {
        std::cout << "Priority queue is empty." << std::endl;
        return;
    }

    size_t level_size = 1;
    size_t i          = 0;

    while (i < m_size)
    {
        for (size_t j = 0; j < level_size && i < m_size; ++j)
        {
            std::cout << m_heap[i++] << " ";
        }
        std::cout << std::endl;
        level_size *= 2;
    }
    std::cout << std::endl;
}

template <typename T, typename Cmp,  typename Container>
constexpr bool my::priority_queue<T, Cmp, Container>::is_valid_heap() const noexcept
{
    if (m_heap.empty())
    {
        return true;
    }

    for (size_t i = 0; i < m_size; ++i)
    {
        size_t leftNode  = left(i);
        size_t rightNode = right(i);

        if (leftNode < m_size && m_cmp(m_heap[leftNode], m_heap[i]))
        {
            return false;
        }

        if (rightNode < m_size && m_cmp(m_heap[rightNode], m_heap[i]))
        {
            return false;
        }
    }

    return true;
}
