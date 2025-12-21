// https://www.geeksforgeeks.org/find-a-mother-vertex-in-a-graph/
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

void dfs(vector<vector<int>> &adj, int src, vector<bool> &visited, vector<int> &ordering)
{
    visited[src] = true;
    for (auto nbr : adj[src])
    {
        if (!visited[nbr])
            dfs(adj, nbr, visited, ordering);
    }
    ordering.push_back(src);
}

vector<int> getTopologicalOrdering(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<bool> visited(n, false);

    vector<int> ordering;

    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(adj, i, visited, ordering);

    return ordering;
}

vector<vector<int>> getReverseGraph(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<vector<int>> rg(n, vector<int>());

    for (int src = 0; src < n; src++)
        for (int nbr : adj[src])
            rg[nbr].push_back(src);

    return rg;
}

vector<int> getMotherVertices(vector<vector<int>> &adj)
{
    vector<int> topoOrdering = getTopologicalOrdering(adj);

    vector<vector<int>> reverseGraph = getReverseGraph(adj);

    int n = adj.size();
    vector<int> motherVertices;
    vector<bool> visited(n, false);
    dfs(reverseGraph, topoOrdering[n - 1], visited, motherVertices);
    return motherVertices;
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
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> motherVertices = getMotherVertices(adj);
    cout << "Mother vertices are: ";
    for (auto v : motherVertices)
        cout << v << " ";
    cout << endl;

    return 0;
}