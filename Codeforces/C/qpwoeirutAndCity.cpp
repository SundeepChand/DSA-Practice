#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

pair<int, int> solve(vector<int> &v, int i, vector<pair<int, int>> &dp)
{
    if (i <= 0)
        return {0, 0};

    if (dp[i].first != -1 and dp[i].second != -1)
        return dp[i];

    if (v[i] > v[i - 1] and v[i] > v[i + 1])
    {
        auto a = solve(v, i - 2, dp);
        a.second++;
        return dp[i] = a;
    }

    pair<int, int> ans;
    int cur = max(v[i - 1], v[i + 1]) + 1 - v[i];
    auto a = solve(v, i - 2, dp);
    auto b = solve(v, i - 1, dp);
    if (a.second + 1 > b.second)
        ans.first = cur + a.first, ans.second = 1 + a.second;
    else if (a.second + 1 == b.second)
        ans.first = min(cur + a.first, b.first), ans.second = b.second;
    else
        ans.first = b.first, ans.second = b.second;
    return dp[i] = ans;
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
        vector<pair<int, int>> dp(n + 1, {-1, -1});
        cout << solve(v, n - 2, dp).first << endl;
    }
    return 0;
}