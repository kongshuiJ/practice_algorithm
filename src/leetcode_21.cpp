//
// Created by kongshui on 5/17/21.
//
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

namespace No1
{
    std::list<int32_t> mergeTwoLists(const std::list<int32_t> &list1, const std::list<int32_t> &list2)
    {
        std::list<int32_t> res;

        auto list1_iter = list1.begin();
        auto list2_iter = list2.begin();

        while ((list1_iter != list1.end()) || (list2_iter != list2.end()))
        {
            if (list1_iter == list1.end())
            {
                res.emplace_back(*list2_iter);
                ++list2_iter;
            } else if (list2_iter == list2.end())
            {
                res.emplace_back(*list1_iter);
                ++list1_iter;
            } else
            {
                if (*list1_iter > *list2_iter)
                {
                    res.emplace_back(*list2_iter);
                    ++list2_iter;
                } else
                {
                    res.emplace_back(*list1_iter);
                    ++list1_iter;
                }
            }
        }

        return res;
    }
}

int32_t main()
{
    std::list<int32_t> list1 = {1, 2, 4};
    std::list<int32_t> list2 = {1, 7, 8, 11};

    std::list<int32_t> res = No1::mergeTwoLists(list1, list2);

    for (auto iter = res.begin(); iter != res.end(); ++iter)
        printf("%d ", *iter);

    printf("\n");

    return 0;
}