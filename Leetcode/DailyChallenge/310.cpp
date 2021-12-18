#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return {0};
        
        vector<set<int>> adj(n, set<int>());
        
        for (auto x: edges)
        {
            int u = x[0], v = x[1];
            adj[u].insert(v);
            adj[v].insert(u);
        }
        
        vector<int> leaves;
        for (int i = 0; i < n; i++)
        {
            if (adj[i].size() == 1)
            {
                leaves.push_back(i);
            }
        }
        
        while (n > 2)
        {
            n -= leaves.size();
            
            vector<int> newLeaves;
            for (int leaf: leaves)
            {
                int nbr = *(adj[leaf].begin());
                adj[nbr].erase(leaf);
                if (adj[nbr].size() == 1)
                    newLeaves.push_back(nbr);
            }
            leaves = newLeaves;
        }
        return leaves;
    }
};