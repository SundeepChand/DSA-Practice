#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[1000001];
int solve(vector<int> &v, int x)
{
    if (x == 0)
        return 1;
    if (dp[x] != -1)
        return dp[x];

    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] <= x)
            ans = (ans + solve(v, x - v[i])) % MOD;
    }
    return (dp[x] = ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(v, x) << endl;
    return 0;
}