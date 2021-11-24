#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasCycle;
    void dfs(vector<vector<int>> &adj, int cur, string &colors, vector<short int> &visited, vector<vector<int>> &dp)
    {
        visited[cur] = 1;

        for (int nbr : adj[cur])
        {
            if (visited[nbr] == 1)
            {
                hasCycle = true;
                return;
            }
            else if (!visited[nbr])
            {
                dfs(adj, nbr, colors, visited, dp);
            }
            for (int i = 0; i < 26; i++)
            {
                dp[cur][i] = max(dp[cur][i], dp[nbr][i]);
            }
        }
        dp[cur][colors[cur] - 'a']++;
        visited[cur] = 2;
    }

    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        int n = colors.length(), m = edges.size();

        vector<vector<int>> adj(n, vector<int>());
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
        }

        hasCycle = false;

        vector<vector<int>> dp(n, vector<int>(26, 0));
        vector<short int> visited(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
                dfs(adj, i, colors, visited, dp);
        }

        if (hasCycle)
            return -1;

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};