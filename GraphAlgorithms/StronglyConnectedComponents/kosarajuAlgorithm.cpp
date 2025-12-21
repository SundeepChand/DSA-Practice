// Kosaraju's Algorithm to find strongly connected components in a graph
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

vector<vector<int>> reverseGraph(const vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<vector<int>> rg(n, vector<int>());
    for (int i = 0; i < n; i++)
    {
        for (int nbr : adj[i])
            rg[nbr].push_back(i);
    }
    return rg;
}

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

vector<int> topologicalSort(const vector<vector<int>> &adj)
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

vector<vector<int>> kosarajuSCC(const vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<vector<int>> rg = reverseGraph(adj);
    vector<int> order = topologicalSort(rg);

    vector<vector<int>> scc;
    vector<bool> visited(n, false);
    for (int x : order)
    {
        if (!visited[x])
        {
            vector<int> comp;
            dfs(adj, x, visited, comp);
            scc.push_back(comp);
        }
    }
    return scc;
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

    vector<vector<int>> scc = kosarajuSCC(adj);
    for (vector<int> x : scc)
    {
        for (int y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}