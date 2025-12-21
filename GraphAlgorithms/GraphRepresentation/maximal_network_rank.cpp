#include <bits/stdc++.h>
using namespace std;

class BruteForceSolution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        int ans = 0;
        int m = roads.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int temp = 0;
                for (int k = 0; k < m; k++)
                {
                    int a = roads[k][0], b = roads[k][1];
                    if (a > b)
                        swap(a, b);
                    if (a == i && b == j)
                        temp++;
                    else
                    {
                        if (a == i || b == i)
                            temp++;
                        if (a == j || b == j)
                            temp++;
                    }
                }
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};

class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        int m = roads.size();
        vector<vector<int>> adj(n, vector<int>(n, 0));
        vector<int> nbrs(n, 0);
        for (int i = 0; i < m; i++)
        {
            int a = roads[i][0], b = roads[i][1];
            adj[a][b] = adj[b][a] = 1;
            nbrs[a]++;
            nbrs[b]++;
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int temp = nbrs[i] + nbrs[j];
                if (adj[i][j])
                    temp--;
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};

int main()
{
    int n = 8;
    vector<vector<int>> v = {{0, 1}, {1, 2}, {2, 3}, {2, 4}, {5, 6}, {5, 7}};

    Solution s;
    cout << s.maximalNetworkRank(n, v) << endl;
    return 0;
}