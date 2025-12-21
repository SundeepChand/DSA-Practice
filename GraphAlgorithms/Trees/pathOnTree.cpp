#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

void dfs(vector<vector<pair<int, int>>> &adj, int src, int par, vector<int> &dist, int cur)
{
    dist[src] = cur;
    for (pair<int, int> nbr : adj[src])
    {
        int v = nbr.first, w = nbr.second;
        if (v != par)
            dfs(adj, v, src, dist, cur + w);
    }
}

vector<int> pathOnTree(int n, int k, vector<vector<int>> edges, vector<vector<int>> queries)
{
    k--;
    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
    for (auto e : edges)
    {
        int u = e[0], v = e[1], w = e[2];
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dist(n);
    dfs(adj, k, -1, dist, 0);

    vector<int> ans;
    for (auto q : queries)
    {
        int s = q[0], d = q[1];
        s--, d--;
        ans.push_back(dist[s] + dist[d]);
    }
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

    int n, k, m, q;
    cin >> n >> k >> m >> q;

    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    vector<vector<int>> queries;
    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        queries.push_back({u, v});
    }

    vector<int> sol = pathOnTree(n, k, edges, queries);
    for (int x : sol)
        cout << x << " ";
    cout << endl;
    return 0;
}