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
    parent[src][0] = par;
    depth[src] = d;

    for (int nbr : adj[src])
    {
        if (nbr != par)
            dfs(adj, nbr, src, d + 1);
    }
}

int LCA(int a, int b)
{
    if (depth[b] > depth[a])
        swap(a, b);
    int diff = depth[a] - depth[b];
    int i = 0;
    while (diff)
    {
        if (diff & 1)
            a = parent[a][i];
        diff >>= 1;
        i++;
    }

    if (a == b)
        return a;

    // a & b are at the same depth
    for (int i = 30; i >= 0; i--)
    {
        if (parent[a][i] != parent[b][i])
            a = parent[a][i], b = parent[b][i];
    }
    return parent[a][0];
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

    depth = vector<int>(n);
    parent = vector<vector<int>>(n, vector<int>(31));
    dfs(adj, 0, -1, 0);

    // Populate the sparse table
    for (int i = 1; i < 31; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int par = parent[j][i - 1];
            if (par == -1)
                parent[j][i] = -1;
            else
                parent[j][i] = parent[par][i - 1];
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //         cout << parent[i][j] << " ";
    //     cout << endl;
    // }

    cout << "LCA:\n";
    cout << LCA(3, 10) << endl;
    cout << LCA(5, 6) << endl;
    cout << LCA(11, 7) << endl;
    return 0;
}