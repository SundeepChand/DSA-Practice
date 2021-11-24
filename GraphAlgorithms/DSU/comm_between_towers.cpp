#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        int n = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    grid[i][j] = n + 1;
                    n++;
                }
            }
        }

        vector<vector<int>> adj(n, vector<int>());

        // Check the rows
        for (int i = 0; i < grid.size(); i++)
        {
            int first = -1;
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] != 0)
                {
                    if (first == -1)
                        first = grid[i][j] - 1;
                    else
                    {
                        adj[first].push_back(grid[i][j] - 1);
                        adj[grid[i][j] - 1].push_back(first);
                    }
                }
            }
        }
        // Check the cols
        for (int i = 0; i < grid[0].size(); i++)
        {
            int first = -1;
            for (int j = 0; j < grid.size(); j++)
            {
                if (grid[j][i] != 0)
                {
                    if (first == -1)
                        first = grid[j][i] - 1;
                    else
                    {
                        adj[first].push_back(grid[j][i] - 1);
                        adj[grid[j][i] - 1].push_back(first);
                    }
                }
            }
        }

        int ans = 0;
        vector<bool> visited(n, false);
        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                ans++;
                q.push(i);
                visited[i] = 1;

                while (!q.empty())
                {
                    int cur = q.front();
                    q.pop();

                    for (int nbr : adj[cur])
                    {
                        if (!visited[nbr])
                        {
                            q.push(nbr);
                            visited[nbr] = 1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}