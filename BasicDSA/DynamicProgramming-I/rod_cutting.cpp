#include <bits/stdc++.h>
using namespace std;

int findMaxCostTD(int n, vector<int> &length, vector<int> &price)
{
    // Recursive soln
    if (n == 0)
        return 0;

    int m = length.size();
    int ans = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        if (length[i] <= n)
        {
            int temp = findMaxCostTD(n - length[i], length, price);
            if (temp != INT_MIN)
                ans = max(ans, price[i] + temp);
        }
    }
    return ans;
}

int findMaxCostBU(int n, vector<int> &length, vector<int> &price)
{
    // Bottom soln
    vector<int> dp(n + 1);
    dp[0] = 0;

    int m = length.size();
    for (int cur_len = 1; cur_len <= n; cur_len++)
    {
        dp[cur_len] = INT_MIN;
        for (int i = 0; i < m; i++)
        {
            int l = length[i], p = price[i];
            if (l <= cur_len && dp[cur_len - l] != INT_MIN)
            {
                dp[cur_len] = max(dp[cur_len], p + dp[cur_len - l]);
            }
        }
    }
    return dp[n];
}

int main()
{
    vector<int> length = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> price = {3, 5, 8, 9, 10, 17, 17, 20};
    int n = 8;  // ans = 22

    // vector<int> length = {2, 4};
    // vector<int> price = {1, 2};
    // int n = 7;

    cout<<findMaxCostBU(n, length, price)<<endl;
    cout<<(findMaxCostBU(n, length, price) == INT_MIN)<<endl;
    cout<<findMaxCostTD(n, length, price)<<endl;
    cout<<(findMaxCostTD(n, length, price) == INT_MIN)<<endl;
    return 0;
}