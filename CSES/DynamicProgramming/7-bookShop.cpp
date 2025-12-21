// 0-1 Knapsack
#include <bits/stdc++.h>
using namespace std;

// int dp[1000][100001];
// int solve(vector<int> &price, vector<int> &page, int cur, int x)
// {
//     if (cur < 0 || x <= 0)
//         return 0;

//     if (dp[cur][x] != -1)
//         return dp[cur][x];

//     int ans = 0;
//     if (price[cur] <= x)
//     {
//         ans = page[cur] + solve(price, page, cur - 1, x - price[cur]);
//     }
//     ans = max(ans, solve(price, page, cur - 1, x));
//     return dp[cur][x] = ans;
// }

int solveBottomUp(vector<int> &price, vector<int> &page, int n, int x)
{
    // Bottom up solution
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (price[i - 1] <= j)
                dp[i][j] = max(page[i - 1] + dp[i - 1][j - price[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][x];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> price(n), page(n);
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> page[i];
    }

    // memset(dp, -1, sizeof(dp));
    cout << solveBottomUp(price, page, n, x) << endl;
    return 0;
}