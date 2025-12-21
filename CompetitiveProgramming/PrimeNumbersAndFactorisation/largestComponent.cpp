#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
#define N 100001
    int dfs(vector<set<int>> &adj, int src, vector<bool> &inList, vector<bool> &visited)
    {
        visited[src] = true;
        int ans = inList[src] ? 1 : 0;
        for (int nbr : adj[src])
        {
            if (!visited[nbr])
            {
                ans += dfs(adj, nbr, inList, visited);
            }
        }
        return ans;
    }

    int largestComponentSize(vector<int> &nums)
    {
        int n = nums.size();

        vector<set<int>> adj(N, set<int>());

        vector<bool> inList(N, false);
        for (int x : nums)
        {
            inList[x] = true;

            // Find the prime factors of x, and add edges appropriately
            int temp = x;
            for (int i = 2; i * i <= temp; i++)
            {
                int ct = 0;
                while (temp % i == 0)
                {
                    temp /= i;
                    ct++;
                }
                if (ct > 0)
                {
                    adj[x].insert(i);
                    adj[i].insert(x);
                }
            }
            if (temp > 1 && temp != x)
            {
                adj[x].insert(temp);
                adj[temp].insert(x);
            }
        }

        // Count the connected component size
        int ans = 0;
        vector<bool> visited(N, false);
        for (int i = 0; i < N; i++)
        {
            if (!visited[i])
            {
                ans = max(ans, dfs(adj, i, inList, visited));
            }
        }
        return ans;
    }
};