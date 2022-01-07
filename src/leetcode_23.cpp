//
// Created by kongshui on 5/17/21.
//
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <array>
#include <queue>

template<typename T>
class Solution
{
public:
    void mergeKLists(std::vector<std::list<T> > &lists)
    {
        std::priority_queue<T, std::vector<T>, std::greater<T> > pq;

        std::vector<bool> empty(lists.size(), false);
        while (true)
        {
            if (lists.size() == std::count(empty.begin(), empty.end(), true))
                break;

            for (int idx = 0; idx < lists.size(); ++idx)
            {
                if (!lists[idx].empty())
                {
                    printf(" %d ", lists[idx].front());
                    pq.push(lists[idx].front());
                    lists[idx].pop_front();
                } else
                    empty[idx] = true;
            }
        }
        printf("\n");
        while (!pq.empty())
        {
            T temp = pq.top();
            pq.pop();
            std::cout << temp << std::endl;
        }
    }
};

int main()
{
    Solution<int> res;
    std::list<int> list1 = {8, 10, 12, 22, 36};
    std::list<int> list2 = {3, 4, 11, 35, 40};
    std::list<int> list3 = {1, 8, 9, 20, 25};

    std::vector<std::list<int>> vec = {list1, list2, list3};

    res.mergeKLists(vec);

    return 0;
}