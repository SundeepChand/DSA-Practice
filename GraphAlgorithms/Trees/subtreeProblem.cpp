#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int dfs(vector<vector<int>> &adj, int src, int par, vector<int> &nnodes)
{
    int ans = 1;
    for (int nbr : adj[src])
    {
        if (nbr != par)
        {
            ans += dfs(adj, nbr, src, nnodes);
        }
    }
    nnodes[src] = ans;
    return ans;
}

vector<int> subtreeProblem(int n, vector<vector<int>> edges, vector<int> queries)
{
    vector<vector<int>> adj(n, vector<int>());

    for (auto x : edges)
    {
        int u = x[0], v = x[1];
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> nnodes(n, 0);
    dfs(adj, 0, -1, nnodes);

    vector<int> ans;
    for (int q : queries)
    {
        ans.push_back(nnodes[q - 1]);
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

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    vector<int> queries(q);
    for (int i = 0; i < q; i++)
    {
        cin >> queries[i];
    }

    vector<int> sol = subtreeProblem(n, edges, queries);
    for (int x : sol)
        cout << x << " ";
    cout << endl;
    return 0;
}