#include <bits/stdc++.h>
using namespace std;

int dp[101][1000001];

int solve(vector<int> &v, int n, int x)
{
    // Bottom up
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = INT_MAX - 100000;
                if (v[i] <= j)
                {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][j - v[i]]);
                }
                if (i > 0)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            }
        }
    }
    return dp[n - 1][x];
}

/*
// More optimised approach
int solve(vector<int> a, int n, int k)
{
    vector<int> dp(1000001);
 
    dp[0] = 0;
    for (int i = 1; i <= k; i++)
    {        
        dp[i] = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            int temp = INT_MAX;
            if (a[j] <= i && dp[i - a[j]] != -1)
            {
                temp = 1 + dp[i - a[j]];
            }
            if (temp < dp[i])
                dp[i] = temp;
        }
        if (dp[i] == INT_MAX)
            dp[i] = -1;
    }
    return dp[k];
}
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    // memset(dp, -1, sizeof(dp));
    int ans = solve(v, n, x);
    if (ans >= INT_MAX - 100000)
        ans = -1;
    cout << ans << endl;
    return 0;
}