#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[1000][1000];

int solve(vector<string> &v, int i, int j)
{
    int n = v.size();
    if (i == n - 1 && j == n - 1)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    if (i < n - 1 && v[i + 1][j] != '*')
    {
        ans = (ans + solve(v, i + 1, j)) % MOD;
    }
    if (j < n - 1 && v[i][j + 1] != '*')
    {
        ans = (ans + solve(v, i, j + 1)) % MOD;
    }
    return (dp[i][j] = ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    memset(dp, -1, sizeof(dp));

    if (v[0][0] == '*')
        cout << 0 << endl;
    else
        cout << solve(v, 0, 0) << endl;
    return 0;
}