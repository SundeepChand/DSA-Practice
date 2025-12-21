#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    3 1 1
    2 5 1
    1 5 5

    op: 21
    */
    int dp[71][71][71];
    int solve(vector<vector<int>> &grid, int r, int c1, int c2)
    {
        int n = grid.size(), m = grid[0].size();
        if (r >= n || c1 < 0 || c1 >= m || c2 < 0 || c2 >= m)
            return 0;

        if (dp[r][c1][c2] != -1)
            return dp[r][c1][c2];

        int ans = 0;
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
                ans = max(
                    ans,
                    solve(grid, r + 1, c1 + i, c2 + j));
        }
        if (c1 == c2)
            ans += grid[r][c1];
        else
            ans += grid[r][c1] + grid[r][c2];
        return dp[r][c1][c2] = ans;
    }

    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(grid, 0, 0, m - 1);
    }
};