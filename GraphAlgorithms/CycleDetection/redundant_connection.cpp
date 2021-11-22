#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int a, b;
    void dfs(vector<vector<int>> &adj, int cur, int p, vector<bool> &visited, vector<int> &parent)
    {
        visited[cur] = true;
        parent[cur] = p;

        for (int i = 0; i < adj[cur].size(); i++)
        {
            if (adj[cur][i] != p && visited[adj[cur][i]])
            {
                a = cur, b = adj[cur][i];
            }
            else if (!visited[adj[cur][i]])
            {
                dfs(adj, adj[cur][i], cur, visited, parent);
            }
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();

        vector<vector<int>> adj(n, vector<int>());

        for (int i = 0; i < n; i++)
        {
            int u = edges[i][0] - 1, v = edges[i][1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        vector<int> parent(n, -1);
        dfs(adj, 0, -1, visited, parent);

        // To find the edges lying on the loop, find path from a to b
        set<pair<int, int>> cedges;
        int cur = b;
        while (cur != a && cur != -1)
        {
            cedges.insert({cur + 1, parent[cur] + 1});
            cur = parent[cur];
        }
        cedges.insert({a + 1, b + 1});

        for (int i = n - 1; i >= 0; i--)
        {
            if (cedges.find({edges[i][0], edges[i][1]}) != cedges.end())
            {
                return edges[i];
            }
            else if (cedges.find({edges[i][1], edges[i][0]}) != cedges.end())
            {
                return edges[i];
            }
        }

        return {a, b};
    }
};

int main()
{
    return 0;
}