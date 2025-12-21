#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/largest-plus-sign/
class Solution1
{
    // O(n^2 * log n) TC
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>> &mines)
    {
        vector<set<int>> row(n, set<int>());
        vector<set<int>> col(n, set<int>());

        for (auto x : mines)
        {
            int r = x[0], c = x[1];
            row[r].insert(c);
            col[c].insert(r);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (row[i].find(j) != row[i].end())
                    continue;
                auto left = row[i].lower_bound(j), right = row[i].upper_bound(j);
                auto up = col[j].lower_bound(i), down = col[j].upper_bound(i);
                int cur = min({i + 1, n - i, j + 1, n - j});
                if (right != row[i].end())
                    cur = min(cur, *right - j);
                if (down != col[j].end())
                    cur = min(cur, *down - i);
                if (left != row[i].begin())
                {
                    left--;
                    cur = min(cur, j - *left);
                }
                if (up != col[j].begin())
                {
                    up--;
                    cur = min(cur, i - *up);
                }
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};

class Solution
{
    // O(n^2) TC
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>> &mines)
    {
        vector<vector<int>> grid(n, vector<int>(n, INT_MAX));
        for (auto x : mines)
            grid[x[0]][x[1]] = 0;

        for (int i = 0; i < n; i++)
        {
            int k1 = 0, k2 = 0;
            for (int j = 0; j < n; j++)
            {
                k1++;
                if (grid[i][j] != 0)
                    grid[i][j] = min(grid[i][j], k1);
                else
                    k1 = 0;

                k2++;
                if (grid[j][i] != 0)
                    grid[j][i] = min(grid[j][i], k2);
                else
                    k2 = 0;
            }

            k1 = 0, k2 = 0;
            for (int j = n - 1; j >= 0; j--)
            {
                k1++;
                if (grid[i][j] != 0)
                    grid[i][j] = min(grid[i][j], k1);
                else
                    k1 = 0;

                k2++;
                if (grid[j][i] != 0)
                    grid[j][i] = min(grid[j][i], k2);
                else
                    k2 = 0;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ans = max(ans, grid[i][j]);
        return ans;
    }
};