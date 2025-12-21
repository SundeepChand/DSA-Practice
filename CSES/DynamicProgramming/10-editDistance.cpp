#include <bits/stdc++.h>
using namespace std;

// int dp[5000][5000];
// int solve(string s, int i, string t, int j)
// {
//     if (i < 0)
//         return j + 1;
//     if (j < 0)
//         return i + 1;
//     if (dp[i][j] != -1)
//         return dp[i][j];

//     if (s[i] == t[j])
//         return solve(s, i - 1, t, j - 1);
//     return dp[i][j] = 1 + min(solve(s, i, t, j - 1), min(solve(s, i - 1, t, j), solve(s, i - 1, t, j - 1)));
// }

int solveBottomUp(string s, string t)
{
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
        }
    }
    return dp[n][m];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    string s, t;
    cin >> s >> t;

    // int n = s.length(), m = t.length();
    // memset(dp, -1, sizeof(dp));
    cout << solveBottomUp(s, t) << endl;
    return 0;
}