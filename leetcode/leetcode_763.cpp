#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <array>


class Solution
{
public:
    std::vector<int> partitionLabels(const std::string &S)
    {
        // aabbaacc
        std::vector<int> result;
        std::array<size_t, 26> postion{};

        size_t start    = 0;
        size_t end      = 0;

        for (size_t index = 0; index < S.length(); ++index)
            postion[S[index] - 'a'] = index;

        for (size_t index = 0; index < S.length(); ++index)
        {
            end = std::max(end, postion[S[index] - 'a']);
            if (index == end)
            {
                result.emplace_back(end - start + 1);
                start = end + 1;
            }
        }

        return result;
    }
};
