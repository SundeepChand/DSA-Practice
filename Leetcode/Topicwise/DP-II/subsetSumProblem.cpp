// Find the number of subsets in an array (containing only positive integers) with sum equal to k
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int subsetSumEqualsK(const vector<int> &nums, int k)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (j == 0)
                dp[i][j] = 1;
            else if (i == 0)
                dp[i][j] = 0;
            else if (nums[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[n][k];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    cout << subsetSumEqualsK(nums, k) << endl;
    return 0;
}