#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <array>

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        // 1, 2, 87, 87, 87, 2, 1
        int other = 0;
        uint16_t size = ratings.size();
        std::vector<int> num(size, 1);

        for (uint16_t index = 0; index < (size - 1); ++index)
        {
            other = index + 1;
            if (ratings[other] > ratings[index])
                num[other] = (num[other] > num[index]) ? num[other] : num[index] + 1;
        }

        for (uint16_t index = size - 1; index > 0; --index)
        {
            other = index - 1;
            if (ratings[other] > ratings[index])
                num[other] = (num[other] > num[index]) ? num[other] : num[index] + 1;
        }

        return accumulate(num.begin(), num.end(), 0);
    }
};
