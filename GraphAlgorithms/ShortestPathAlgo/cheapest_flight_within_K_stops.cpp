#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int cheapestPriceUtil(vector<vector<pair<int, int>>> &adj, int src, int dst, int k)
    {
        int n = adj.size();
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        set<vector<int>> s;
        s.insert({0, 0, src});
        while (!s.empty())
        {
            auto cur = *(s.begin());
            s.erase(s.begin());

            int distSoFar = cur[1], n_nodes = cur[0], u = cur[2];
            for (int i = 0; i < adj[u].size(); i++)
            {
                int v = adj[u][i].first, w = adj[u][i].second;
                if (n_nodes <= k && distSoFar + w < dist[v])
                {
                    dist[v] = distSoFar + w;
                    s.insert({n_nodes + 1, dist[v], v});
                }
            }
        }
        if (dist[dst] == INT_MAX)
            return -1;
        return dist[dst];
    }

    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());

        for (auto x : flights)
        {
            int u = x[0], v = x[1], w = x[2];
            adj[u].push_back({v, w});
        }

        return cheapestPriceUtil(adj, src, dst, k);
    }
};