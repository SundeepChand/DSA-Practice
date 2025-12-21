#include <bits/stdc++.h>
using namespace std;

int max_d = INT_MAX;
void dfs(vector<vector<int>> &adj, int cur, int parent, int start, int depth, vector<bool> &visited)
{
    visited[cur] = 1;

    for (auto x : adj[cur])
    {
        if (visited[x] && x == start && x != parent)
        {
            max_d = min(max_d, depth + 1);
        }
        else if (!visited[x])
        {
            dfs(adj, x, cur, start, depth + 1, visited);
        }
    }
}

int solve(int n, vector<vector<int>> edges)
{
    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0] - 1, v = edges[i][1] - 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        vector<bool> visited(n, false);
        max_d = INT_MAX;
        dfs(adj, i, -1, i, 0, visited);
        ans = min(ans, max_d);
    }
    if (ans == INT_MAX)
        return -1;
    return ans;
}

int main()
{
    int n = 8;
    vector<vector<int>> edges = {
        {1, 2},
        {2, 3},
        {3, 1},
        {2, 4},
        {4, 5},
        {5, 6},
        {6, 7},
        {7, 8},
        {8, 3},
    };
    cout << solve(n, edges) << endl;
    return 0;
}