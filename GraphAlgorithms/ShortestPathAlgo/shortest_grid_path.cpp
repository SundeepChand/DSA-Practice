#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dijkstra(vector<vector<int>> &grid, int i, int j)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[i][j] = grid[i][j];

        set<pair<int, pair<int, int>>> s;
        s.insert({dist[i][j], {i, j}});
        while (!s.empty())
        {
            auto cur = *(s.begin());
            s.erase(s.begin());

            i = cur.second.first, j = cur.second.second;
            int distSoFar = cur.first;
            vector<int> di{-1, 1, 0, 0};
            vector<int> dj{0, 0, -1, 1};
            for (int x = 0; x < 4; x++)
            {
                int ni = i + di[x], nj = j + dj[x];
                if (ni >= 0 && nj >= 0 && ni < n && nj < m && distSoFar + grid[ni][nj] < dist[ni][nj])
                {
                    s.erase({dist[ni][nj], {ni, nj}});
                    dist[ni][nj] = distSoFar + grid[ni][nj];
                    s.insert({dist[ni][nj], {ni, nj}});
                }
            }
        }
        return dist[n - 1][m - 1];
    }

    //Function to return the minimum cost to react at bottom
    //right cell from top left cell.
    int minimumCostPath(vector<vector<int>> &grid)
    {
        return dijkstra(grid, 0, 0);
    }
};