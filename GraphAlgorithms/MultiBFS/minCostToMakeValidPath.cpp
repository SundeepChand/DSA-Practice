#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
    {
        int n = adj.size();
        deque<pair<int, int>> s;

        vector<int> dist = vector<int>(n, INT_MAX);
        dist[src] = 0;
        s.push_back({0, 0});

        while (!s.empty())
        {
            auto cur = s.front();
            s.pop_front();

            int u = cur.second, d = cur.first;
            for (auto nbr : adj[u])
            {
                int v = nbr.first, w = nbr.second;
                if (d + w < dist[v])
                {
                    dist[v] = d + w;
                    if (w == 0)
                        s.push_front({dist[v], v});
                    else
                        s.push_back({dist[v], v});
                }
            }
        }
        return dist;
    }

    int minCost(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        vector<vector<pair<int, int>>> adj(m * n, vector<pair<int, int>>());

        vector<int> di = {0, 0, 1, -1}, dj = {1, -1, 0, 0};
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    int ni = i + di[k], nj = j + dj[k];
                    if (ni >= 0 && nj >= 0 && ni < m && nj < n)
                    {
                        int u = n * i + j, v = n * ni + nj;
                        int w = (grid[i][j] != (k + 1));
                        adj[u].push_back({v, w});
                    }
                }
            }
        }
        vector<int> dist = dijkstra(adj, 0);
        return dist[n * m - 1];
    }
};