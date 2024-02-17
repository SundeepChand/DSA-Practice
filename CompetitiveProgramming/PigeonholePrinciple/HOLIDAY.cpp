#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int dfs(vector<vector<pair<int, int>>> &adj, int src, int parent)
{
    int ctr = 1;
    for (auto [v, w] : adj[src])
    {
        if (v != parent)
        {
            ctr += dfs(adj, v, src);
        }
    }
    return ctr;
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
    int tc = t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
        vector<vector<int>> edges(n - 1, vector<int>(2));
        vector<int> dist(n, -1);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v, w;
            u--, v--;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            edges[i][0] = u, edges[i][1] = v;
        }

        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int x = dfs(adj, edges[i][0], edges[i][1]);
            ans += 2 * min(x, n - x);
        }

        cout << "Case #" << (tc - t) << ": " << ans << endl;
    }
    return 0;
}