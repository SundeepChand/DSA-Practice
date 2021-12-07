#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void flip(vector<vector<int>> &grid, int i, bool row = 0)
    {
        if (row)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                grid[i][j] = !grid[i][j];
            }
        }
        else
        {
            for (int j = 0; j < grid.size(); j++)
            {
                grid[j][i] = !grid[j][i];
            }
        }
    }
    int countZeroes(vector<vector<int>> &grid, int i)
    {
        int ctr = 0;
        for (int j = 0; j < grid.size(); j++)
        {
            if (grid[j][i] == 0)
                ctr++;
        }
        return ctr;
    }

    int matrixScore(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            if (grid[i][0] == 0)
            {
                flip(grid, i, 1);
            }
        }

        for (int j = 0; j < m; j++)
        {
            int ctz = countZeroes(grid, j);
            if (ctz > (n - ctz))
            {
                flip(grid, j, 0);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int cur = 0;
            for (int j = 0; j < m; j++)
            {
                cur = (cur << 1) | grid[i][j];
            }
            ans += cur;
        }
        return ans;
    }
};