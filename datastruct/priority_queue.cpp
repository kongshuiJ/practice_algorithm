//
// Created by kongshui on 5/17/21.
//
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <array>

template<typename T>
class PriorityQueue
{
private:
    int32_t pq_size;
    T *pq;

    T left(int32_t idx)
    {
        return 2 * idx;
    }

    T right(int32_t idx)
    {
        return 2 * idx + 1;
    }

    T parent(int32_t idx)
    {
        return idx / 2;
    }

    void swim(int32_t idx)
    {
        while (idx > 1 && less(parent(idx), idx))
        {
            exchange(parent(idx), idx);
            idx = parent(idx);
        }
    }

    void sink(int32_t idx)
    {
        while (left(idx) <= pq_size)
        {
            int32_t older = left(idx);
            if (right(idx) <= pq_size && less(older, right(idx)))
                older = right(idx);

            if (less(older, idx)) break;

            exchange(idx, older);
            idx = older;
        }
    }

    void exchange(int32_t idx1, int32_t idx2)
    {
        T tmp = pq[idx1];
        pq[idx1] = pq[idx2];
        pq[idx2] = tmp;
    }

    bool less(int32_t idx1, int32_t idx2)
    {
        return pq[idx1] < pq[idx2];
    }

public:
    PriorityQueue() = delete;

    PriorityQueue(int32_t size) : pq_size(0), pq(nullptr)
    {
        // Index 0 is will not use, so size + 1
        pq = new T[size + 1];
    }

    ~PriorityQueue()
    {
        if (pq != nullptr)
        {
            delete pq;
            pq = nullptr;
        }
    }

    T getMax()
    {
        return pq[1];
    }

    bool insert(T val)
    {
        pq_size++;

        pq[pq_size] = val;
        swim(pq_size);
    }

    bool deleteMax()
    {
        exchange(1, pq_size);
        pq[pq_size] = 0;
        pq_size--;
        sink(1);
        return true;
    }
};

int32_t main()
{
    constexpr int32_t size = 10;

    PriorityQueue<int32_t> ttt(size);

    for (int32_t idx = 0; idx < size; ++idx)
        ttt.insert(rand() % 99);

    for (int idx = 0; idx < size; ++idx)
    {
        printf("%d\n", ttt.getMax());
        ttt.deleteMax();
    }

    return 0;
}