#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;
    bool solve(vector<int> &nums, int i, int cur, int tot)
    {
        if (cur == tot)
            return true;
        if (i < 0)
            return false;

        if (dp[i][cur] != -1)
            return dp[i][cur];

        bool ans = false;
        if (cur + nums[i] <= tot)
            ans = ans || solve(nums, i - 1, cur + nums[i], tot);
        ans = ans || solve(nums, i - 1, cur, tot);
        return (dp[i][cur] = ans);
    }

    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int tot = 0;
        for (auto x : nums)
            tot += x;
        if (tot % 2 == 1)
            return false;
        tot /= 2;
        dp = vector<vector<int>>(n, vector<int>(tot + 1, -1));
        return solve(nums, n - 1, 0, tot);
    }
};