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

    int diff = depth[u] - depth[v];
    int i = 0;
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
        {
            u = parent[u][i], v = parent[v][i];
        }
    }
    return parent[u][0];
}

vector<int> LCA(vector<vector<int>> &adj, vector<vector<int>> &queries)
{
    int n = adj.size();
    depth = vector<int>(n);
    parent = vector<vector<int>>(n, vector<int>(31));
    // precompute
    dfs(adj, 0, -1, 0);
    for (int j = 1; j < 31; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (parent[i][j - 1] == -1)
            {
                parent[i][j] = -1;
                continue;
            }
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }

    // find lca
    vector<int> ans;
    for (auto x : queries)
    {
        ans.push_back(lca(x[0], x[1]));
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

    int n;
    cin >> n;

    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < n; i++)
    {
        int ctr;
        cin >> ctr;
        int u = i, v;
        for (int j = 0; j < ctr; j++)
        {
            cin >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    int m;
    cin >> m;

    vector<vector<int>> queries(m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        queries[i] = {u, v};
    }

    vector<int> ans = LCA(adj, queries);
    for (int x : ans)
        cout << x << endl;
    return 0;
}