#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int dfs(vector<vector<int>> &adj, int src, int par, int &score)
{
    int ans = 1;
    for (int nbr : adj[src])
    {
        if (nbr != par)
            ans += dfs(adj, nbr, src, score);
    }
    score += ans;
    return ans;
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

    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int score = 0;
        dfs(adj, i, -1, score);
        ans = max(ans, score);
    }
    cout << ans << endl;

    return 0;
}