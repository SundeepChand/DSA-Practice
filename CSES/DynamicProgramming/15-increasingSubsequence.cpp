#include <bits/stdc++.h>
using namespace std;

// O(n^2) DP approach
int solve(vector<int> &v)
{
    int n = v.size();
    vector<int> dp(n, 1);
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[j] < v[i])
            {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

// Modified DP approach. This approach can be modified to run in O(n * log n) time.
int solve2(vector<int> &v)
{
    int n = v.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = INT_MIN;
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        int j = lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
        if (v[i] < dp[j])
        {
            dp[j] = v[i];
            ans = max(ans, j);
        }
        // for (int j = 1; j <= n; j++)
        // {
        //     if (dp[j - 1] < v[i] && v[i] < dp[j])
        //     {
        //         dp[j] = v[i];
        //         ans = max(ans, j);
        //     }
        // }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // cout << solve(v) << endl;
    cout << solve2(v) << endl;
    return 0;
}