#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int prims(vector<vector<vector<int>>> &adj)
    {
        int n = adj.size();

        vector<bool> mstSet(n, false);

        int minCost = 0, ctr = 0;
        priority_queue<vector<int>> pq;
        for (auto nbrs : adj[0])
        {
            pq.push({-nbrs[1], nbrs[0]});
        }
        mstSet[0] = true;

        while (!pq.empty())
        {
            auto front = pq.top();
            pq.pop();

            int cost = -front[0], u = front[1];
            if (mstSet[u])
                continue;

            mstSet[u] = true;
            minCost += cost;
            ctr++;
            // if (ctr >= n - 1)
            //     break;
            for (vector<int> nbrs : adj[u])
            {
                int v = nbrs[0], w = nbrs[1];
                if (!mstSet[v])
                {
                    pq.push({-w, v});
                }
            }
        }
        return minCost;
    }

    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();

        vector<vector<vector<int>>> adj(n, vector<vector<int>>());
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                auto pt1 = points[i], pt2 = points[j];
                int w = abs(pt1[0] - pt2[0]) + abs(pt1[1] - pt2[1]);
                adj[i].push_back({j, w});
                adj[j].push_back({i, w});
            }
        }

        return prims(adj);
    }
};