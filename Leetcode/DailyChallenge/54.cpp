#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int n = matrix.size(), m = matrix[0].size();

        vector<int> ans;

        vector<int> mv = {m, n - 1};
        int cur_dir = 0, i = 0, j = -1;
        while (mv[0] > 0 || mv[1] > 0)
        {
            int dir_idx = cur_dir % 2;
            if (mv[dir_idx] == 0)
                break;
            for (int k = 0; k < mv[dir_idx]; k++)
            {
                i += direction[cur_dir][0], j += direction[cur_dir][1];
                ans.push_back(matrix[i][j]);
            }
            mv[dir_idx]--;
            cur_dir = (1 + cur_dir) % 4;
        }
        return ans;
    }
};

class SolutionBF
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;

        int n = matrix.size(), m = matrix[0].size();
        /*
            j -> [k, m - 1 - k]
            i -> [k + 1, n - 1 - k]
            j -> [m - 2 - k, k]
            i -> [n - 2 - k, k + 1]        
        */
        int depth = max(ceil(double(n) / 2), ceil(double(m) / 2));
        for (int k = 0; k < depth; k++)
        {
            for (int j = k; j <= m - 1 - k; j++)
                ans.push_back(matrix[k][j]);
            if (ans.size() == n * m)
                break;
            for (int i = k + 1; i <= n - 1 - k; i++)
                ans.push_back(matrix[i][m - 1 - k]);
            if (ans.size() == n * m)
                break;
            for (int j = m - 2 - k; j >= k; j--)
                ans.push_back(matrix[n - 1 - k][j]);
            if (ans.size() == n * m)
                break;
            for (int i = n - 2 - k; i >= k + 1; i--)
                ans.push_back(matrix[i][k]);
            if (ans.size() == n * m)
                break;
        }
        return ans;
    }
};
