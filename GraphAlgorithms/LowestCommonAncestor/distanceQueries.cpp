#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

vector<int> depth;
vector<vector<int>> parent;

void dfs(vector<vector<int>> &adj, int src, int par, int d)
{
    depth[src] = d;
    parent[src][0] = par;
    for (int nbr : adj[src])
    {
        if (nbr != par)
            dfs(adj, nbr, src, d + 1);
    }
}

int lca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);

    // binary lifting
    int diff = depth[u] - depth[v], i = 0;
    while (diff)
    {
        if (diff & 1)
            u = parent[u][i];
        diff >>= 1;
        i++;
    }

    if (u == v)
        return u;

    for (int i = 30; i >= 0; i--)
    {
        if (parent[u][i] != parent[v][i])
            u = parent[u][i], v = parent[v][i];
    }
    return parent[u][0];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, q;
    cin >> n >> q;

    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // precompute depth & parent
    depth = vector<int>(n);
    parent = vector<vector<int>>(n, vector<int>(31));
    dfs(adj, 0, -1, 0);
    for (int j = 1; j < 31; j++)
    {
        for (int i = 0; i < n; i++)
        {
            int p = parent[i][j - 1];
            if (p == -1)
                parent[i][j] = -1;
            else
                parent[i][j] = parent[p][j - 1];
        }
    }

    // process queries
    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        cout << (depth[u] + depth[v] - 2 * depth[lca(u, v)]) << endl;
    }

    return 0;
}