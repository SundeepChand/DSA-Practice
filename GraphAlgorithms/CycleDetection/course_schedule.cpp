#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(vector<vector<int>> &adj, int cur, int p, vector<bool> &visited, vector<bool> &stack)
    {
        stack[cur] = true;

        bool isCyclic = false;
        for (int x : adj[cur])
        {
            if (stack[x])
            {
                return true;
            }
            else if (!visited[x])
            {
                isCyclic = isCyclic || dfs(adj, x, cur, visited, stack);
            }
        }
        stack[cur] = false;
        visited[cur] = true;

        return isCyclic;
    }

    bool canFinish(int n, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(n, vector<int>());

        for (int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0], v = prerequisites[i][1];
            adj[u].push_back(v);
        }

        bool isCyclic = false;
        vector<bool> visited(n, false), stack(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
                isCyclic = isCyclic || dfs(adj, i, -1, visited, stack);
        }
        return !isCyclic;
    }
};

int main()
{
    return 0;
}