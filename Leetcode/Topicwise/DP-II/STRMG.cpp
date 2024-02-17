#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int dp[5001][5001][2];

int solve(string &a, int i, string &b, int j, int prev)
{
    int n = a.size(), m = b.size();
    if (i >= n and j >= m)
        return 0;
    if (dp[i - 1][j - 1][prev] != -1)
        return dp[i - 1][j - 1][prev];

    char prevChar = prev == 0 ? a[i - 1] : b[j - 1];
    int ans = INT_MAX;
    if (i >= n)
        ans = min(ans, (b[j] != prevChar) + solve(a, i, b, j + 1, 1));
    else if (j >= m)
        ans = min(ans, (a[i] != prevChar) + solve(a, i + 1, b, j, 0));
    else
    {
        ans = min(ans, (a[i] != prevChar) + solve(a, i + 1, b, j, 0));
        ans = min(ans, (b[j] != prevChar) + solve(a, i, b, j + 1, 1));
    }
    return dp[i - 1][j - 1][prev] = ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        string a, b;
        cin >> a;
        cin >> b;

        a.insert(a.begin(), '#');
        b.insert(b.begin(), '#');

        memset(dp, -1, sizeof(dp));

        cout << solve(a, 1, b, 1, 0) << endl;
    }
    return 0;
}