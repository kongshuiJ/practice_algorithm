#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <array>

class Solution
{
public:
    bool canPlaceFlowers(std::vector<int> &flowerbed, int n)
    {
        if(!n)
            return true;

        if (flowerbed.size() == 1)
            return !flowerbed[0];

        const int size  = flowerbed.size();
        int num         = 0;
        int left_index  = 0;
        int right_index = 0;

        for (int index = 0; index < size; ++index)
        {
            left_index  = index - 1;
            right_index = index + 1;

            if (flowerbed[index])
                continue;

            if (index == 0)
            {
                if (!flowerbed[right_index])
                {
                    flowerbed[index] = 1;
                    ++num;
                }
            } else if (index == (size - 1))
            {
                if (!flowerbed[left_index])
                {
                    flowerbed[index] = 1;
                    ++num;
                }
            } else
            {
                if (!flowerbed[left_index] && !flowerbed[right_index])
                {
                    flowerbed[index] = 1;
                    ++num;
                }
            }
        }

        return num >= n;
    }
};
