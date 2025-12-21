#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &adj, int cur, int p, vector<bool> &visited)
{
    visited[cur] = true;

    bool isCyclic = false;
    for (int x : adj[cur])
    {
        if (!visited[x])
        {
            isCyclic = isCyclic || dfs(adj, x, cur, visited);
        }
        else if (x != p && visited[x])
        {
            return true;
        }
    }
    return isCyclic;
}

bool isCyclic(int n, vector<vector<int>> edges)
{
    vector<vector<int>> adj(n, vector<int>());

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0] - 1, v = edges[i][1] - 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    bool isCyclic = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            isCyclic = isCyclic || dfs(adj, i, -1, visited);
    }
    return isCyclic;
}

int main()
{
    return 0;
}