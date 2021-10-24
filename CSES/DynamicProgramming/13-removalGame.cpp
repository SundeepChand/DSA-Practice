#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[5000][5000][2];
ll solve(vector<ll> &v, ll s, ll e, bool isturn)
{
    if (s > e)
        return 0;

    if (dp[s][e][isturn] != -1)
        return dp[s][e][isturn];
    ll ans = 0;
    if (isturn)
    {
        ans = max(solve(v, s + 1, e, !isturn) + v[s], solve(v, s, e - 1, !isturn) + v[e]);
    }
    else
    {
        ans = min(solve(v, s + 1, e, !isturn), solve(v, s, e - 1, !isturn));
    }
    return dp[s][e][isturn] = ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(v, 0, n - 1, true) << endl;
    return 0;
}