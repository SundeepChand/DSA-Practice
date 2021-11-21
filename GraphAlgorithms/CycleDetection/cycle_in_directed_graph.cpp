#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &adj, int cur, int p, vector<bool> &gray, vector<bool> &black)
{
    gray[cur] = true;

    bool isCyclic = false;
    for (auto x : adj[cur])
    {
        if (gray[x])
        {
            return true;
        }
        else if (!black[x])
        {
            isCyclic = isCyclic || dfs(adj, x, cur, gray, black);
        }
    }
    gray[cur] = false;
    black[cur] = true;
    return isCyclic;
}

bool isCyclic(int n, vector<vector<int>> edges)
{
    vector<vector<int>> adj(n, vector<int>());

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0] - 1, v = edges[i][1] - 1;
        adj[u].push_back(v);
    }

    vector<bool> black(n, false);
    vector<bool> gray(n, false);
    bool isCyclic = false;
    for (int i = 0; i < n; i++)
    {
        if (!black[i])
            isCyclic = isCyclic || dfs(adj, i, -1, gray, black);
    }
    return isCyclic;
}

int main()
{
    int n = 2;
    vector<vector<int>> edges = {{1, 2}, {2, 1}};
    cout << isCyclic(n, edges) << endl;
    return 0;
}