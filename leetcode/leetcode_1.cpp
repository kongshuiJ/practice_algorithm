//
// Created by kongshui on 5/12/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <array>

using namespace std;

/*
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 *
 * */

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector <pair<int, int>> nums1;
        for (int i = 0; i < nums.size(); ++i)
            nums1.push_back(make_pair(nums[i], i));
        sort(nums1.begin(), nums1.end());
        int i = 0, j = nums1.size() - 1;
        vector<int> ret;
        while (i < j)
        {
            if (nums1[i].first + nums1[j].first == target)
            {
                ret.push_back(nums1[i].second);
                ret.push_back(nums1[j].second);
                printf("%d, %d\n", nums1[i].second, nums1[j].second);
                ++i;
            } else
                nums1[i].first + nums1[j].first < target ? ++i : --j;

            printf("i: %d, j: %d\n", i, j);
        }

        return ret;
    }
};

int main()
{
    Solution tmp;

    std::vector<int> nums{2, 3, 6, 7, 11, 15};

    auto result = tmp.twoSum(nums, 9);

    for (auto qqq: result)
        printf(" %d ", qqq);

    return 0;
}