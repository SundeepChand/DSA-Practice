#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m));
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    dist[i][j] = 0;
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();

            int r = cur.first, c = cur.second;
            vector<int> dr = {-1, 1, 0, 0}, dc = {0, 0, -1, 1};
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc])
                {
                    dist[nr][nc] = 1 + dist[r][c];
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }
        return dist;
    }
};
