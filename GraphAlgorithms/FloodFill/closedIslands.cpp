#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &grid, int i, int j, int n, int m, bool &closed)
    {
        if (i == 0 || (i == n - 1) || j == 0 || (j == m - 1))
            closed = false;
        grid[i][j] = -1;

        vector<int> di = {-1, 1, 0, 0};
        vector<int> dj = {0, 0, -1, 1};
        for (int k = 0; k < 4; k++)
        {
            int ni = i + di[k], nj = j + dj[k];
            if (ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] == 0)
                dfs(grid, ni, nj, n, m, closed);
        }
    }

    int closedIsland(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();

        int ctr = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    bool isClosed = true;
                    dfs(grid, i, j, n, m, isClosed);
                    if (isClosed)
                        ctr++;
                }
            }
        }
        return ctr;
    }
};