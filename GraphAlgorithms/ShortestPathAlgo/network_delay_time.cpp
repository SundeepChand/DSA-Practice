#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dijkstra(vector<vector<pair<int, int>>> &adj, int src)
    {
        int n = adj.size();
        vector<int> dist(n, INT_MAX);

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
                    s.insert({dist[v], v});
                }
            }
        }

        int ans = 0;
        for (auto x : dist)
        {
            ans = max(ans, x);
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
    }

    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());

        for (int i = 0; i < times.size(); i++)
        {
            int u = times[i][0] - 1, v = times[i][1] - 1, w = times[i][2];
            adj[u].push_back({v, w});
        }

        return dijkstra(adj, k - 1);
    }
};