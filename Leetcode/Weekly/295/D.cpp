#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> dp;
    vector<vector<bool>> visited;

    int solve(vector<vector<int>> &grid, int i, int j)
    {
        int n = grid.size(), m = grid[0].size();

        if (dp[i][j] != -1)
            return dp[i][j];

        visited[i][j] = true;

        int di[] = {0, 0, -1, 1};
        int dj[] = {-1, 1, 0, 0};
        int ans = INT_MAX - 10000000;

        for (int k = 0; k < 4; k++)
        {
            int ni = i + di[k], nj = j + dj[k];
            if (ni >= 0 and nj >= 0 and ni < n and nj < m and !visited[ni][nj])
            {
                ans = min(ans, (grid[i][j] == 1) + solve(grid, ni, nj));
            }
        }
        visited[i][j] = false;

        return ans;
        // return dp[i][j] = ans;
    }

    int minimumObstacles(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();

        dp = vector<vector<int>>(n, vector<int>(m, -1));
        dp[n - 1][m - 1] = 0;

        visited = vector<vector<bool>>(n, vector<bool>(m, false));

        return solve(grid, 0, 0);
    }
};