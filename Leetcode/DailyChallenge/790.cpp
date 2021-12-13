#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

class Solution
{
public:
    int n;
    vector<vector<int>> dp;

    int solve(int i, bool t1, bool t2)
    {
        if (i == n)
            return 1;

        int state = 0;
        if (t1)
            state |= 1;
        if (t2)
            state |= 2;
        if (dp[i][state] != -1)
            return dp[i][state];

        bool t3, t4;
        t3 = t4 = (i + 1 < n);
        int count = 0;
        if (t1 && t2)
            count += solve(i + 1, true, true), count %= MOD;
        if (!t1 && !t2)
            count += solve(i + 1, true, true), count %= MOD;
        if (t1 && t2 && t3 && t4)
        {
            count += solve(i + 1, false, false), count %= MOD;
            count += solve(i + 1, false, true), count %= MOD;
            count += solve(i + 1, true, false), count %= MOD;
        }
        if (t1 && !t2 && t3 && t4)
        {
            count += solve(i + 1, false, true), count %= MOD;
            count += solve(i + 1, false, false), count %= MOD;
        }
        if (!t1 && t2 && t3 && t4)
        {
            count += solve(i + 1, true, false), count %= MOD;
            count += solve(i + 1, false, false), count %= MOD;
        }
        return (dp[i][state] = count % MOD);
    }

    int numTilings(int n)
    {
        this->n = n;
        dp = vector<vector<int>>(n, vector<int>(4, -1));
        return solve(0, true, true);
    }
};