
#include "priority_queue.h"
namespace my {

    template <typename T, typename Compare, typename Container>
    priority_queue<T, Compare, Container>::priority_queue(const value_compare& cmp)
        : m_heap(),
          m_size(0),
          m_cmp(cmp)
    {
    }

    template <typename T, typename Compare, typename Container>
    priority_queue<T, Compare, Container>::priority_queue(const container_type& input, const value_compare& cmp)
        : m_heap(input),
          m_size(input.size()),
          m_cmp(cmp)
    {
        this->make_heap();
    }

    template <typename T, typename Compare, typename Container>
    priority_queue<T, Compare, Container>::priority_queue(std::initializer_list<value_type> initList,
                                                          const value_compare&              cmp)
        : m_heap(initList),
          m_size(initList.size()),
          m_cmp(cmp)
    {
        for (const_reference elem : initList)
        {
            m_heap.push_back(elem);
        }

        this->make_heap();
    }

    template <typename T, typename Compare, typename Container>
    template <typename RandomAccessIterator>
    priority_queue<T, Compare, Container>::priority_queue(RandomAccessIterator first, RandomAccessIterator last,
                                                          const value_compare& cmp)
        : m_heap(first, last),
          m_size(std::distance(first, last)),
          m_cmp(cmp)
    {
        this->make_heap();
    }

    //-------------------------_copy_-----------------------------//
    template <typename T, typename Compare, typename Container>
    priority_queue<T, Compare, Container>::priority_queue(const priority_queue& other)
        : m_heap(other.m_heap),
          m_size(other.m_size),
          m_cmp(other.m_cmp)
    {
    }

    template <typename T, typename Compare, typename Container>
    priority_queue<T, Compare, Container>& priority_queue<T, Compare, Container>::operator=(const priority_queue& other)
    {
        if (this != &other)
        {
            m_heap = other.m_heap;
            m_size = other.m_size;
            m_cmp  = other.m_cmp;
        }

        return *this;
    }

    //-------------------------_move_-----------------------------//
    template <typename T, typename Compare, typename Container>
    priority_queue<T, Compare, Container>::priority_queue(priority_queue&& other) noexcept
        : m_heap(std::move(other.m_heap)),
          m_size(other.m_size),
          m_cmp(std::move(other.m_cmp))
    {
        other.m_size = 0;
    }

    template <typename T, typename Compare, typename Container>
    priority_queue<T, Compare, Container>& priority_queue<T, Compare, Container>::operator=(
        priority_queue&& other) noexcept
    {
        if (this != &other)
        {
            m_heap       = std::move(other.m_heap);
            m_size       = other.m_size;
            m_cmp        = std::move(other.m_cmp);
            other.m_size = 0;
        }

        return *this;
    }

    //-----------------------------_-make_heap-_-------------------------------//
    template <typename T, typename Compare, typename Container>
    void priority_queue<T, Compare, Container>::make_heap()
    {
        for (long i = (m_size / 2) - 1; i >= 0; --i)
        {
            this->heapify_down(i);
        }
    }

    //-----------------------------_-parent-_-------------------------------//

    template <typename T, typename Compare, typename Container>
    inline typename priority_queue<T, Compare, Container>::index_t priority_queue<T, Compare, Container>::parent(
        const index_t ind) const noexcept
    {
        return (ind - 1) / 2;
    }

    //-----------------------------_-left-_-------------------------------//
    template <typename T, typename Compare, typename Container>
    inline typename priority_queue<T, Compare, Container>::index_t priority_queue<T, Compare, Container>::left(
        const index_t ind) const noexcept
    {
        return 2 * ind + 1;
    }

    //-----------------------------_-right-_-------------------------------//
    template <typename T, typename Compare, typename Container>
    inline typename priority_queue<T, Compare, Container>::index_t priority_queue<T, Compare, Container>::right(
        const index_t ind) const noexcept
    {
        return 2 * ind + 2;
    }

    //-----------------------------_-heapify_down-_-------------------------------//
    template <typename T, typename Compare, typename Container>
    void priority_queue<T, Compare, Container>::heapify_down(const std::size_t ind)
    {
        index_t largest  = ind;
        index_t leftInd  = left(ind);
        index_t rightInd = right(ind);

        if (leftInd < m_size && m_cmp(m_heap[leftInd], m_heap[largest]))
            largest = leftInd;

        if (rightInd < m_size && m_cmp(m_heap[rightInd], m_heap[largest]))
            largest = rightInd;

        if (largest != ind)
        {
            std::swap(m_heap[ind], m_heap[largest]);
            this->heapify_down(largest);
        }
    }

    //-----------------------------_-push-_-------------------------------//
    template <typename T, typename Compare, typename Container>
    void priority_queue<T, Compare, Container>::push(const_reference val)
    {
        m_heap.push_back(val);
        ++m_size;

        index_t index = m_size - 1;
        while (index > 0 && m_cmp(val, m_heap[parent(index)]))
        {
            std::swap(m_heap[index], m_heap[parent(index)]);
            index = parent(index);
        }
    }

    //-----------------------------_-pop-_-------------------------------//
    template <typename T, typename Compare, typename Container>
    void priority_queue<T, Compare, Container>::pop()
    {
        if (m_size == 0)
        {
            return;
        }

        std::swap(m_heap[0], m_heap[m_size - 1]);
        m_heap.pop_back();
        --m_size;

        this->heapify_down(0); // Restore the heap property
    }

    //-----------------------------_-extract_top-_-------------------------------//
    template <typename T, typename Compare, typename Container>
    typename priority_queue<T, Compare, Container>::value_type priority_queue<T, Compare, Container>::extract_top()
    {
        if (m_size == 0)
        {
            throw std::out_of_range("priority_queue is empty");
        }

        value_type topValue = m_heap.front();

        std::swap(m_heap[0], m_heap[m_size - 1]);
        m_heap.pop_back();
        --m_size;

        this->heapify_down(0); // Restore the heap property

        return topValue;
    }

    //-----------------------------_-top-_-------------------------------//
    template <typename T, typename Compare, typename Container>
    inline typename priority_queue<T, Compare, Container>::const_reference priority_queue<T, Compare, Container>::top()
        const
    {
        if (m_size == 0)
        {
            throw std::out_of_range("priority_queue is empty");
        }

        return m_heap.front();
    }

    //-----------------------------_-empty-_-------------------------------//
    template <typename T, typename Compare, typename Container>
    inline bool priority_queue<T, Compare, Container>::empty() const noexcept
    {
        return m_size == 0;
    }

    //-----------------------------_-size-_-------------------------------//
    template <typename T, typename Compare, typename Container>
    inline typename priority_queue<T, Compare, Container>::size_type priority_queue<T, Compare, Container>::size()
        const noexcept
    {
        return m_size;
    }

    //-----------------------------_-print-_-------------------------------//
    template <typename T, typename Compare, typename Container>
    void priority_queue<T, Compare, Container>::print() const noexcept
    {
        if (m_heap.empty())
        {
            std::cout << "Priority queue is empty." << std::endl;
            return;
        }

        for (index_t i = 0; i < m_size; ++i)
        {
            std::cout << m_heap[i] << " ";
        }
        std::cout << std::endl;
    }

    template <typename T, typename Compare, typename Container>
    void priority_queue<T, Compare, Container>::print_level() const noexcept
    {
        if (m_heap.empty())
        {
            std::cout << "Priority queue is empty." << std::endl;
            return;
        }

        std::size_t levelSize = 1;
        index_t     curIndex  = 0;

        while (curIndex < m_size)
        {
            for (std::size_t j = 0; j < levelSize && curIndex < m_size; ++j)
            {
                std::cout << m_heap[curIndex++] << " ";
            }
            std::cout << std::endl;
            levelSize *= 2;
        }
        std::cout << std::endl;
    }

    template <typename T, typename Compare, typename Container>
    bool priority_queue<T, Compare, Container>::is_valid_heap() const noexcept
    {
        if (m_heap.empty())
        {
            return true;
        }

        for (std::size_t i = 0; i < m_size; ++i)
        {
            index_t leftInd  = left(i);
            index_t rightInd = right(i);

            if (leftInd < m_size && m_cmp(m_heap[leftInd], m_heap[i]))
            {
                return false;
            }

            if (rightInd < m_size && m_cmp(m_heap[rightInd], m_heap[i]))
            {
                return false;
            }
        }

        return true;
    }

} // namespace my
