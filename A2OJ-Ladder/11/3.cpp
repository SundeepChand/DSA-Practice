#include <bits/stdc++.h>
using namespace std;

bool visited[100001];
int32_t dp[100001][2];
int solve(vector<int> &v, int cur, int par)
{
    if (v[cur] % 2 != par)
        return 0;

    if (dp[cur][par] != -1)
        return dp[cur][par];

    int ans = INT_MAX - 110000, n = v.size();
    int l = cur - v[cur], r = cur + v[cur];

    visited[cur] = true;
    if (l >= 0 && !visited[l])
        ans = min(ans, 1 + solve(v, l, par));
    if (r < n && !visited[r])
        ans = min(ans, 1 + solve(v, r, par));
    visited[cur] = false;
    return (dp[cur][par] = ans);
}

int32_t main()
{
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

    vector<int> ans;
    memset(dp, -1, sizeof(dp));
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++)
    {
        ans.push_back(solve(v, i, v[i] % 2));
    }

    for (int x : ans)
    {
        if (x < INT_MAX - 110000)
            cout << x;
        else
            cout << -1;
        cout << " ";
    }
    return 0;
}