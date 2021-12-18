#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        int ans = 0;
        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();

            int r = cur.first, c = cur.second;
            vector<int> dr = {-1, 1, 0, 0};
            vector<int> dc = {0, 0, -1, 1};
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == 1)
                {
                    dist[nr][nc] = 1 + dist[r][c];
                    q.push({nr, nc});
                    grid[nr][nc] = 2;
                    ans = max(ans, dist[nr][nc]);
                    fresh--;
                }
            }
        }
        if (fresh > 0)
            return -1;
        return ans;
    }
};