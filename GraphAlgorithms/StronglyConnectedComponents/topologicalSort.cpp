#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

void dfs(vector<vector<int>> &adj, int src, vector<bool> &visited, vector<int> &order)
{
    visited[src] = true;
    for (int neighbor : adj[src])
    {
        if (!visited[neighbor])
            dfs(adj, neighbor, visited, order);
    }
    order.push_back(src);
}

vector<int> topologicalSort(vector<vector<int>> &adj)
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
    }

    vector<int> order = topologicalSort(adj);
    for (int x : order)
        cout << x << " ";
    cout << endl;
    return 0;
}