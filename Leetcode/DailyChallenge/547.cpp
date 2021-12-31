#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &isConnected, int src, vector<bool> &visited)
    {
        visited[src] = true;
        for (int i = 0; i < isConnected.size(); i++)
        {
            if (isConnected[src][i] && !visited[i])
                dfs(isConnected, i, visited);
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();

        int ans = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(isConnected, i, visited);
                ans++;
            }
        }
        return ans;
    }
};