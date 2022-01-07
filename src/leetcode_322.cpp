//
// Created by kongshui on 5/17/21.
//
#include <iostream>
#include <vector>

namespace No1
{

    int32_t dp(std::vector<int32_t> &coins, int32_t amount)
    {
        if (amount == 0) return 0;
        if (amount < 0) return -1;

        int32_t res = INT32_MAX;

        for (auto &coin : coins)
        {
            int32_t subProblem = dp(coins, amount - coin);
            if (subProblem == -1) continue;
            res = std::min(res, subProblem + 1);
        }

        return res == INT32_MAX ? -1 : res;
    }

    int32_t coinChange(std::vector<int32_t> &coins, int32_t amount)
    {
        return dp(coins, amount);
    }
}

namespace No2
{
    constexpr int32_t invalid_value = -666;
    int32_t *memo;

    int32_t dp(std::vector<int32_t> &coins, int32_t amount)
    {
        if (amount == 0) return 0;
        if (amount < 0) return -1;

        if (memo[amount] != invalid_value)
            return memo[amount];

        int32_t res = INT32_MAX;
        for (auto &coin:coins)
        {
            int32_t subProblem = dp(coins, amount - coin);
            if (subProblem == -1) continue;
            res = std::min(res, subProblem + 1);
        }

        memo[amount] = (res == INT32_MAX) ? -1 : res;

        return memo[amount];
    }

    int32_t coinChange(std::vector<int32_t> &coins, int32_t amount)
    {
        memo = new int32_t[amount + 1];
        for (int32_t idx = 0; idx <= amount; ++idx)
            memo[idx] = invalid_value;

        return dp(coins, amount);
    }
}

namespace No3
{
    int32_t array_size = INT32_MAX;
    int32_t valid_value = INT32_MAX;

    int32_t coinChange(std::vector<int32_t> &coins, int32_t amount)
    {
        array_size = amount + 1;
        int32_t *dp = new int32_t[array_size];
        // 数组大小为 array_size，初始值也为 array_size

        for (int32_t idx = 0; idx <= amount; ++idx)
            dp[idx] = array_size;

        // base case
        dp[0] = 0;
        // 外层 for 循环在遍历所有状态的所有取值
        for (int32_t idx = 0; idx <= amount; ++idx)
        {
            for (auto &coin:coins)
            {
                if (idx - coin < 0)
                    continue;

                dp[idx] = std::min(dp[idx], 1 + dp[idx - coin]);
            }
        }

        valid_value = (dp[amount] == array_size) ? -1 : dp[amount];
        delete dp;
        return valid_value;
    }
}

int32_t main()
{

    std::vector<int32_t> vec = {1, 2, 3};
    int32_t amount = 22;

    printf("No1: %d\n", No1::coinChange(vec, amount));
    printf("No2: %d\n", No2::coinChange(vec, amount));
    printf("No3: %d\n", No3::coinChange(vec, amount));

    return 0;
}