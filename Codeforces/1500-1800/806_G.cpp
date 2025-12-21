#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int solve(vector<int> &a, int i, int d, int k, int dp[][31])
{
    int n = a.size();
    if (i >= n)
        return 0;
    if (dp[i][d] != -1)
        return dp[i][d];

    int p1 = -k + a[i] / (1 << d) + solve(a, i + 1, d, k, dp);

    int nd = (d < 30) ? (d + 1) : d;

    int p2 = a[i] / (1 << nd) + solve(a, i + 1, nd, k, dp);
    int ans = max(p1, p2);

    // cerr << i << " " << d << " " << p1 << " " << p2 << " " << ans << endl;
    return dp[i][d] = ans;
}

int solve2(vector<int> &a, int k)
{
    int n = a.size();

    vector<vector<int>> dp(n + 1, vector<int>(31));

    dp[n] = vector<int>(31, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        dp[i][30] = 0;
        for (int j = 29; j >= 0; j--)
        {
            dp[i][j] = max(
                -k + a[i] / (1 << j) + dp[i + 1][j],
                a[i] / (1 << (j + 1)) + dp[i + 1][j + 1]);
        }
    }
    return dp[0][0];
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
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int dp[n + 1][31];
        memset(dp, -1, sizeof(dp));

        cout << solve(a, 0, 0, k, dp) << endl;
    }
    return 0;
}