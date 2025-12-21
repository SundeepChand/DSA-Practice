// https://www.geeksforgeeks.org/count-of-n-digit-numbers-whose-sum-of-digits-equals-to-given-sum/
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int dp[5000][1000];

int solve(int n, int sum)
{
    if (n == 0)
        return sum == 0;
    if (sum == 0)
        return 0;
    if (n == 1)
        return (sum <= 9 && sum > 0);
    if (dp[n][sum] != -1)
        return dp[n][sum];
    int ans = 0;
    for (int i = 0; i <= 9; i++)
    {
        if (sum - i >= 0)
            ans += solve(n - 1, sum - i);
    }
    return dp[n][sum] = ans;
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
    memset(dp, -1, sizeof(dp));

    while (t--)
    {
        int n, sum;
        cin >> n >> sum;
        cout << solve(n, sum) << endl;
    }
    return 0;
}