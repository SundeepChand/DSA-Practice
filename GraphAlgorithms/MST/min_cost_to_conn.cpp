#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int prims(int n, vector<vector<pair<int, int>>> &adj)
    {
        int ans = 0;

        vector<bool> visited(n, false);
        visited[0] = true;

        priority_queue<pair<int, int>> pq;
        for (auto nbrs : adj[0])
        {
            pq.push({-nbrs.second, nbrs.first});
        }

        while (!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();

            int w = -cur.first, v = cur.second;
            if (!visited[v])
            {
                ans += w;
                visited[v] = true;
                for (auto nbrs : adj[v])
                {
                    if (!visited[nbrs.first])
                    {
                        pq.push({-nbrs.second, nbrs.first});
                    }
                }
            }
        }

        return ans;
    }

    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();

        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
        for (int i = 0; i < n; i++)
        {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; j++)
            {
                int x2 = points[j][0], y2 = points[j][1];
                adj[i].push_back({j, abs(x1 - x2) + abs(y1 - y2)});
                adj[j].push_back({i, abs(x1 - x2) + abs(y1 - y2)});
            }
        }

        return prims(n, adj);
    }
};