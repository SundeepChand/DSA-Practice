#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

// int dp[100][1000001];

// int solve(vector<int> &v, int cur, int x)
// {
//     if (x == 0)
//         return 1;
//     if (cur < 0)
//         return 0;
//     if (dp[cur][x] != -1)
//         return dp[cur][x];

//     int ans = 0;
//     if (v[cur] <= x)
//         ans = (ans + solve(v, cur, x - v[cur])) % MOD;
//     ans = (ans + solve(v, cur - 1, x)) % MOD;
//     return (dp[cur][x] = ans);
// }

int solveBottomUp(vector<int> &v, int x)
{
    // Bottom up soln
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (j == 0)
                dp[i][j] = 1;
            else
            {
                if (v[i] <= j)
                    dp[i][j] = (dp[i][j] + dp[i][j - v[i]]) % MOD;
                if (i > 0)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            }
        }
    }
    return dp[n - 1][x];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    // memset(dp, -1, sizeof(dp));
    cout << solveBottomUp(v, x) << endl;
    return 0;
}