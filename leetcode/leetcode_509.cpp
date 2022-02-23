//
// Created by kongshui on 5/17/21.
//
#include <iostream>
#include <vector>

int32_t helper(int32_t *memo, int32_t n)
{
    if (n == 0 || n == 1) return n;
    if (memo[n] != 0) return memo[n];
    memo[n] = helper(memo, n - 1) + helper(memo, n - 2);
    return memo[n];
}

int32_t fib(int32_t n)
{
    int32_t *memo = new int32_t[n + 1];
    return helper(memo, n);
}

int32_t fib_dp(int32_t n)
{
    if (n < 1) return 0;

    std::vector<int32_t> dp;

    // base case
    dp.clear();
    dp.emplace_back(0);
    dp.emplace_back(1);

    for (int idx = 2; idx <= n; ++idx)
        dp.emplace_back(dp[idx - 1] + dp[idx - 2]);

    return dp[n];
}

int32_t fib_opt_dp(int32_t n)
{
    if (n < 1) return 0;

    int32_t pre = 0;
    int32_t cur = 1;
    int32_t sum = 0;

    for (int32_t idx = 2; idx <= n; ++idx)
    {
        sum = pre + cur;
        pre = cur;
        cur = sum;
    }

    return cur;
}

int32_t main()
{
    int32_t idx = 20;

    printf("fib loop    : %d\n", fib(idx));
    printf("fib dp      : %d\n", fib_dp(idx));
    printf("fib opt_dp  : %d\n", fib_opt_dp(idx));

    return 0;
}