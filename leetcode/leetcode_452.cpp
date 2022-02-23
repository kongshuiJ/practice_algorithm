#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <array>

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.empty())
            return 0;
        
        int size = points.size();

        std::sort(points.begin(), points.end(),
                  [](std::vector<int> &left, std::vector<int> &right)
                  { return left[1] < right[1]; });

        auto pre = points[0][1];
        for (size_t index = 1; index < points.size(); ++index)
        {
            if (points[index][0] > pre)
                pre = points[index][1];
            else
                --size;
        }

        return size;
    }
};
