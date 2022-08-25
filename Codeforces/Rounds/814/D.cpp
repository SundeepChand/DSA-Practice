#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int64_t solve(vector<int> &v, int i, int x, int16_t dp[][8192])
{
    if (i < 0)
        return 0;
    if (i == 0)
        return x != 0;
    if (dp[i][x] != -1)
        return dp[i][x];

    int16_t ans;
    if (x == 0)
    {
        ans = solve(v, i - 1, v[i - 1], dp);
    }
    else
    {
        ans = 1 + min(
                      solve(v, i - 1, v[i - 1], dp),
                      solve(v, i - 1, v[i - 1] ^ x, dp));
    }
    return dp[i][x] = ans;
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
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int16_t dp[n][8192];
        memset(dp, -1, sizeof(dp));
        cout << solve(v, n - 1, v[n - 1], dp) << endl;
    }
    return 0;
}