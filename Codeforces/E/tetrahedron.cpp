// https:// codeforces.com/problemset/problem/166/E
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[2][10000001];

int solve(int pos, int n)
{

    dp[0][1] = 0, dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[0][i] = (3LL * dp[1][i - 1]) % MOD;
        dp[1][i] = (((2LL * dp[1][i - 1]) % MOD) + dp[0][i - 1]) % MOD;
    }
    return dp[pos][n];

    // Memoized sol
    // if (n == 1)
    //     return pos != 0;
    // if (dp[pos][n] != -1)
    //     return dp[pos][n];

    // int ans = 0;
    // if (pos == 0)
    //     ans = (3LL * solve(1, n - 1)) % MOD;
    // else
    //     ans = (((2LL * solve(1, n - 1)) % MOD) + solve(0, n - 1)) % MOD;
    // return dp[pos][n] = ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << solve(0, n) << endl;
    return 0;
}