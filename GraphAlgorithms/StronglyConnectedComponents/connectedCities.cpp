#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

void dfs(const vector<vector<int>> &adj, int src, vector<bool> &visited, vector<int> &order)
{
    visited[src] = true;
    for (int nbr : adj[src])
    {
        if (!visited[nbr])
            dfs(adj, nbr, visited, order);
    }
    order.push_back(src);
}

vector<int> topologicalOrder(const vector<vector<int>> &adj)
{
    int n = adj.size();

    vector<int> order;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(adj, i, visited, order);
    }
    reverse(order.begin(), order.end());
    return order;
}

int SCC(const vector<vector<int>> &adj, const vector<vector<int>> &rev)
{
    int n = adj.size();
    vector<int> order = topologicalOrder(rev);
    vector<bool> visited(n, false);

    int ans = 0;
    for (int i : order)
    {
        if (!visited[i])
        {
            vector<int> comp;
            dfs(adj, i, visited, comp);
            ans++;
        }
    }
    return ans;
}

bool solve(int n, vector<vector<int>> roads)
{
    vector<vector<int>> adj(n, vector<int>()), rev(n, vector<int>());
    for (vector<int> edge : roads)
    {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        rev[v].push_back(u);
    }

    // Return true if there is a single SCC
    int scc = SCC(adj, rev);
    return scc == 1;
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

    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    cout << solve(n, edges) << endl;
    return 0;
}