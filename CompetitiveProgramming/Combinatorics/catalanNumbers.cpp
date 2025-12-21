#include <bits/stdc++.h>
using namespace std;

class SolutionTopDown
{
public:
    int dp[20];
    int solve(int n)
    {
        if (n == 0 || n == 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans += (solve(i - 1) * solve(n - i));
        return dp[n] = ans;
    }
    int numTrees(int n)
    {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};

class SolutionBottomUp
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = 0;
            for (int j = 1; j <= i; j++)
                dp[i] += dp[j - 1] * dp[i - j];
        }
        return dp[n];
    }
};