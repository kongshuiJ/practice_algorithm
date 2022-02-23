//
// Created by kongshui on 5/17/21.
//
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

typedef std::list<std::list<int8_t>> LinkedList;

namespace No1
{
    LinkedList res;

    void backtrack(std::vector<int8_t> &nums, std::list<int8_t> &track)
    {
        if (track.size() == nums.size())
        {
            res.emplace_back(track);
            return;
        }

        for (int8_t idx = 0; idx < nums.size(); ++idx)
        {
            if (track.end() != std::find(track.begin(), track.end(), nums[idx]))
                continue;

            track.emplace_back(nums[idx]);
            backtrack(nums, track);
            track.pop_back();
        }
    }

    LinkedList permute(std::vector<int8_t> &nums)
    {
        std::list<int8_t> track;
        backtrack(nums, track);

        return res;
    }
}

int32_t main()
{
    std::vector<int8_t > vec = {1, 2, 3, 4};
    int32_t amount = 22;

    LinkedList res = No1::permute(vec);

    printf("SUCCESS:%d\n", res.size());

    for(const auto & list: res)
    {
        for(const auto &num: list)
        {
            printf("%d", num);
        }
        printf("\n");
    }

    return 0;
}