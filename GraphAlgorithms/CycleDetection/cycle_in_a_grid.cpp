#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool bfs(vector<vector<char>> &grid, int i, int j, vector<vector<pair<int, int>>> &p)
    {
        // cout<<"Here"<<endl;
        int n = grid.size(), m = grid[0].size();

        // Perform BFS at current.
        char cur_char = grid[i][j];
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] -= 30;
        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();

            int x = cur.first, y = cur.second;
            vector<int> dx{-1, 1, 0, 0};
            vector<int> dy{0, 0, -1, 1};
            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                {
                    if (!(p[x][y].first == nx && p[x][y].second == ny) && grid[nx][ny] == (cur_char - 30))
                    {
                        return true;
                    }
                    else if (grid[nx][ny] == cur_char)
                    {
                        q.push({nx, ny});
                        grid[nx][ny] -= 30;
                        p[nx][ny] = cur;
                    }
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size();

        vector<vector<pair<int, int>>> p(n, vector<pair<int, int>>(m, {-1, -1}));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] >= int('a'))
                {
                    if (bfs(grid, i, j, p))
                        return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}