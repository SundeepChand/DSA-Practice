#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void bfs(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &visited)
    {
        int n = grid.size(), m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = 1;
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
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1' && !visited[nr][nc])
                {
                    q.push({nr, nc});
                    visited[nr][nc] = 1;
                }
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    bfs(grid, i, j, visited);
                    count++;
                }
            }
        }
        return count;
    }
};