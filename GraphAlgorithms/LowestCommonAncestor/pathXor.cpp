#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

vector<int> depth, xor_path;
vector<vector<int>> parent;

void dfs(vector<vector<int>> &adj, int src, int par, int d, vector<int> &a)
{
    depth[src] = d;
    parent[src][0] = par;
    if (par != -1)
        xor_path[src] = a[src] ^ xor_path[par];
    for (int nbr : adj[src])
    {
        if (nbr != par)
            dfs(adj, nbr, src, d + 1, a);
    }
}

int lca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);

    // perform binary lifting
    int diff = depth[u] - depth[v], i = 0;
    while (diff)
    {
        if (diff & 1)
        {
            u = parent[u][i];
        }
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

vector<int> pathXor(int n, vector<int> a, vector<vector<int>> edges, vector<vector<int>> queries)
{
    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int u = edges[i][0], v = edges[i][1];
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // pre-compute sparse table
    depth = xor_path = vector<int>(n);
    parent = vector<vector<int>>(n, vector<int>(31));
    xor_path[0] = a[0];
    dfs(adj, 0, -1, 0, a);

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

    // find the lca for each query
    vector<int> ans;
    for (auto x : queries)
    {
        int u = x[0], v = x[1];
        u--, v--;
        int l = lca(u, v);
        ans.push_back(xor_path[u] ^ xor_path[v] ^ a[l]);
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
    }
    return 0;
}