#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int cities(vector<vector<pair<int, int>>> &adj, int src, int thresh)
    {
        int n = adj.size();
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        set<pair<int, int>> s;
        s.insert({0, src});
        while (!s.empty())
        {
            auto front = *(s.begin());
            s.erase(s.begin());

            int u = front.second, d = front.first;
            for (auto nbr : adj[u])
            {
                int v = nbr.first, w = nbr.second;
                if (w + d < dist[v])
                {
                    s.erase({dist[v], v});
                    dist[v] = w + d;
                    s.insert({dist[v], v});
                }
            }
        }

        int res = -1;
        for (auto x : dist)
        {
            if (x <= thresh)
                res++;
        }
        return res;
    }

    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
        for (auto x : edges)
        {
            int u = x[0], v = x[1], w = x[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> n_cities(n);
        for (int i = 0; i < n; i++)
        {
            vector<bool> visited(n, false);
            set<int> s;
            n_cities[i] = cities(adj, i, distanceThreshold);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (n_cities[i] <= n_cities[ans])
                ans = i;
        }
        return ans;
    }
};