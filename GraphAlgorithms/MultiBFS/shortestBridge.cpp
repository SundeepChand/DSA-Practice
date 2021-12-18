#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    void dfs(vector<vector<int>> &grid, int i, int j, vector<pair<int, int>> &v)
    {
        int n = grid.size();
        vector<int> di = {-1, 1, 0, 0}, dj = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++)
        {
            int ni = i + di[k], nj = j + dj[k];
            if (ni < 0 || nj < 0 || ni >= n || nj >= n || grid[ni][nj] == 0)
            {
                v.push_back({i, j});
                break;
            }
        }

        grid[i][j] = -1;

        for (int k = 0; k < 4; k++)
        {
            int ni = i + di[k], nj = j + dj[k];
            if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 1)
                dfs(grid, ni, nj, v);
        }
    }

    int shortestBridge(vector<vector<int>> &grid)
    {
        int n = grid.size();

        vector<pair<int, int>> b1, b2;
        bool first = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    if (first)
                    {
                        dfs(grid, i, j, b1);
                        first = false;
                    }
                    else
                        dfs(grid, i, j, b2);
                }
            }
        }

        int ans = INT_MAX;
        for (auto x1 : b1)
        {
            for (auto x2 : b2)
            {
                ans = min(ans, abs(x1.first - x2.first) + abs(x1.second - x2.second));
            }
        }
        return ans - 1;
    }
};

class Solution
{
public:
    void dfs(vector<vector<int>> &grid, int i, int j, queue<pair<int, int>> q, vector<vector<bool>> &visited, vector<vector<int>> &dist)
    {
        int n = grid.size();
        dist[i][j] = 0;
        q.push({i, j});
        visited[i][j] = true;

        vector<int> di = {-1, 1, 0, 0}, dj = {0, 0, -1, 1};
        for (int k = 0; k < 4; k++)
        {
            int ni = i + di[k], nj = j + dj[k];
            if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 1 && !visited[ni][nj])
            {
                dfs(grid, ni, nj, q, visited, dist);
            }
        }
    }

    int shortestBridge(vector<vector<int>> &grid)
    {
        int n = grid.size();

        vector<vector<int>> dist = vector<vector<int>>(n, vector<int>(n, INT_MAX));

        vector<vector<bool>> visited = vector<vector<bool>>(n, vector<bool>(n, false));

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    dfs(grid, i, j, q, visited, dist);
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
                if (nr >= 0 && nc >= 0 && nr < n && nc < n && !visited[nr][nc])
                {
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                    dist[nr][nc] = 1 + dist[r][c];
                }
            }
        }
    }
};