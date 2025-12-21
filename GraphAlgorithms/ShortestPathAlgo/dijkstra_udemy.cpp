#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
{
    int n = adj.size();
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    dist[src] = 0;

    set<pair<int, int>> s;
    s.insert({0, src});
    while (!s.empty())
    {
        auto cur = *(s.begin());
        s.erase(s.begin());

        int d = cur.first, u = cur.second;
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first, w = adj[u][i].second;
            if (d + w < dist[v])
            {
                s.erase({dist[v], v});
                dist[v] = d + w;
                parent[v] = u;
                s.insert({dist[v], v});
            }
        }
    }

    vector<int> ans;
    int cur = n - 1;
    while (cur != -1)
    {
        ans.push_back(cur + 1);
        cur = parent[cur];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> shortestPath(vector<vector<int>> roads, int n)
{
    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());

    for (int i = 0; i < roads.size(); i++)
    {
        int u = roads[i][0] - 1, v = roads[i][1] - 1, w = roads[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    return dijkstra(adj, 0);
}