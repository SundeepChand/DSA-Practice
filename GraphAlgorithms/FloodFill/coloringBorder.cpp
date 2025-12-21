#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &grid, int i, int j, int c, int ori, vector<vector<bool>> &visited)
    {
        int n = grid.size(), m = grid[0].size();

        visited[i][j] = true;

        // Check if cur square is a border
        vector<int> di = {-1, 1, 0, 0}, dj = {0, 0, -1, 1};
        bool isBorder = false;
        for (int k = 0; k < 4; k++)
        {
            int ni = i + di[k], nj = j + dj[k];
            if (ni < 0 || nj < 0 || ni >= n || nj >= m || grid[ni][nj] != ori)
                isBorder = true;
        }
        for (int k = 0; k < 4; k++)
        {
            int ni = i + di[k], nj = j + dj[k];
            if (ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] == ori && !visited[ni][nj])
                dfs(grid, ni, nj, c, ori, visited);
        }
        if (isBorder)
            grid[i][j] = c;
        else
            grid[i][j] = ori;
    }
    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col, int color)
    {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        dfs(grid, row, col, color, grid[row][col], visited);
        return grid;
    }
};