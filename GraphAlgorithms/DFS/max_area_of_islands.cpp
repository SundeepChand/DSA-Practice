#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bfs(vector<vector<int>> &grid, int i, int j)
    {
        int n = grid.size(), m = grid[0].size();

        int ctr = 1;
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = -1;

        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();

            int x = cur.first, y = cur.second;
            if (x > 0 && grid[x - 1][y] == 1)
            {
                q.push({x - 1, y});
                grid[x - 1][y] = -1;
                ctr++;
            }
            if (x < (n - 1) && grid[x + 1][y] == 1)
            {
                q.push({x + 1, y});
                grid[x + 1][y] = -1;
                ctr++;
            }
            if (y > 0 && grid[x][y - 1] == 1)
            {
                q.push({x, y - 1});
                grid[x][y - 1] = -1;
                ctr++;
            }
            if (y < (m - 1) && grid[x][y + 1] == 1)
            {
                q.push({x, y + 1});
                grid[x][y + 1] = -1;
                ctr++;
            }
        }
        return ctr;
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    int temp = bfs(grid, i, j);
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}