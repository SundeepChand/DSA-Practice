#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int dp[501][501];
int solve(vector<int> &v1, vector<int> &v2, int i, int k)
{
    if (i <= 0)
        return 0;

    if (dp[i][k] != -1)
        return dp[i][k];

    int ans = (v1[i] - v1[i - 1]) * v2[i - 1] + solve(v1, v2, i - 1, k);
    for (int j = 1; j <= k; j++)
    {
        if (i - j >= 1)
        {
            ans = min(ans, (v1[i] - v1[i - j - 1]) * v2[i - j - 1] + solve(v1, v2, i - j - 1, k - j));
        }
    }
    return dp[i][k] = ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, l, k;
    cin >> n >> l >> k;
    memset(dp, -1, sizeof(dp));

    vector<int> v1(n), v2(n);
    for (int i = 0; i < n; i++)
        cin >> v1[i];
    for (int i = 0; i < n; i++)
        cin >> v2[i];

    v1.push_back(l);
    cout << solve(v1, v2, n, k) << endl;
    return 0;
}