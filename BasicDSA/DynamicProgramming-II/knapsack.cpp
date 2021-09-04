#include <bits/stdc++.h>
using namespace std;

int maxValueTDUtil(const vector<int> &wt, const vector<int> &prices, int W, int i, vector<vector<int>> &dp)
{
    if (i < 0 || W <= 0)
        return 0;

    if (dp[W][i] != -1)
        return dp[W][i];

    int ans = maxValueTDUtil(wt, prices, W, i - 1, dp);
    if (wt[i] <= W)
    {
        ans = max(
            ans,
            prices[i] + maxValueTDUtil(wt, prices, W - wt[i], i - 1, dp)
        );
    }
    return (dp[W][i] = ans);
}

int maxValueTD(const vector<int> &wt, const vector<int> &prices, int W)
{
    int n = wt.size();
    vector<vector<int>> dp(W + 1, vector<int>(n, -1));
    return maxValueTDUtil(wt, prices, W, n - 1, dp);
}

int maxValueBU(const vector<int> &wt, const vector<int> &prices, int W)
{
    int n = wt.size();
    vector<vector<int>> dp(W + 1, vector<int>(n + 1));

    for (int i = 0; i <= W; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (wt[j - 1] <= i)
            {
                dp[i][j] = max(dp[i][j - 1], prices[j - 1] + dp[i - wt[j - 1]][j - 1]);
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    return dp[W][n];
}

int main()
{
    vector<int> wt {2, 7, 3, 4};
    vector<int> prices {5, 20, 20, 10};
    int W = 11;

    cout<<maxValueTD(wt, prices, W)<<endl;
    cout<<maxValueBU(wt, prices, W)<<endl;
    return 0;
}