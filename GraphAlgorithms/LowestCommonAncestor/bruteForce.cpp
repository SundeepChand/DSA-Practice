#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

vector<int> depth, parent;

void dfs(vector<vector<int>> &adj, int src, int par)
{
    parent[src] = par;
    depth[src] = 1 + depth[par];
    for (int nbr : adj[src])
    {
        if (nbr != par)
            dfs(adj, nbr, src);
    }
}

int LCA(int a, int b)
{
    if (depth[b] > depth[a])
        swap(a, b);
    while (depth[a] != depth[b])
        a = parent[a];
    while (a != b)
        a = parent[a], b = parent[b];
    return a;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Assume 0 to be the root
    depth = parent = vector<int>(n);
    depth[0] = 0;
    dfs(adj, 0, 0);

    // LCA
    cout << LCA(3, 10) << endl;
    cout << LCA(5, 6) << endl;
    cout << LCA(11, 7) << endl;
    return 0;
}