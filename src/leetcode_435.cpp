#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <array>

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(),
                [](std::vector<int> &before, std::vector<int> &after)
                { return before[1] < after[1]; });

        uint16_t removed = 0;
        auto pre         = intervals[0][1];

        for (auto index = 1; index < intervals.size(); ++index)
        {
            if (intervals[index][0] < pre)
                ++removed;
            else
                pre = intervals[index][1];
        }

        return removed;
    }
};
