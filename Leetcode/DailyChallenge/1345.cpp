#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minJumps(vector<int> &a)
    {
        int n = a.size();
        unordered_map<int, vector<int>> u;
        for (int i = 0; i < n; i++)
        {
            u[a[i]].push_back(i);
        }

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            vector<int> &nbrs = u[a[cur]];
            nbrs.push_back(cur + 1);
            nbrs.push_back(cur - 1);
            for (int v : nbrs)
            {
                if (v >= 0 && v < n && dist[v] == INT_MAX)
                {
                    dist[v] = 1 + dist[cur];
                    if (v == n - 1)
                        return dist[n - 1];
                    q.push(v);
                }
            }
            nbrs.clear();
        }
        return dist[n - 1];
    }
};