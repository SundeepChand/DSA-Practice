#include <bits/stdc++.h>
using namespace std;

#define INF (INT_MAX - 1e8)

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<int> s(n), c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    for (int j = 0; j < n; j++)
        cin >> c[j];

    vector<vector<int>> dp(n, vector<int>(3));
    dp[0][0] = c[0], dp[0][1] = dp[0][2] = INF;

    int ans = INF;

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = c[i], dp[i][1] = dp[i][2] = INF;
        for (int j = 0; j < i; j++)
        {
            if (s[j] < s[i])
            {
                dp[i][1] = min(dp[i][1], c[i] + dp[j][0]);
                dp[i][2] = min(dp[i][2], c[i] + dp[j][1]);
            }
        }
        ans = min(ans, dp[i][2]);
    }
    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}