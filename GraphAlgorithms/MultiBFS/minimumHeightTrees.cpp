#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n <= 1)
            return {0};
        vector<set<int>> adj(n, set<int>());

        for (auto e : edges)
        {
            int u = e[0], v = e[1];
            adj[u].insert(v);
            adj[v].insert(u);
        }

        vector<int> leaves;
        for (int i = 0; i < n; i++)
        {
            if (adj[i].size() == 1)
                leaves.push_back(i);
        }

        while (n > 2)
        {
            vector<int> newLeaves;
            for (int l : leaves)
            {
                int v = *(adj[l].begin());
                adj[v].erase(l);
                n--;
                if (adj[v].size() == 1)
                    newLeaves.push_back(v);
            }
            leaves = newLeaves;
        }
        return leaves;
    }
};