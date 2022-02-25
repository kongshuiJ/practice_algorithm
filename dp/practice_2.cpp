#include <iostream>
#include <vector>
#include <array>

int getMinimum(const std::vector<int> &money_vec, int money)
{
    std::vector<int> minimum_vec(money + 1, INT32_MAX);
    minimum_vec[0] = 0;

    for (int idx = 1; idx <= money; ++idx)
    {
        for (int money_idx: money_vec)
        {
            if (idx - money_idx < 0)
                continue;

            if (money >= money_idx && minimum_vec[idx - money_idx] != INT32_MAX)
                minimum_vec[idx] = std::min(minimum_vec[idx], minimum_vec[idx - money_idx] + 1);
        }
    }

    for (int idx = 0; idx < minimum_vec.size(); ++idx)
    {
        std::cout << idx << ": " << minimum_vec[idx] << std::endl;
    }

    return minimum_vec[money];
}

int main()
{
    std::vector<int> vec = {2, 5, 7};

    std::cout << "min money num: " << getMinimum(vec, 27) << std::endl;

    return 0;
}