#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> indeg(n, 0), outdeg(n, 0);
        for (auto x : trust)
        {
            int u = x[0], v = x[1];
            u--, v--;
            indeg[v]++;
            outdeg[u]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (indeg[i] == n - 1 && outdeg[i] == 0)
                return i + 1;
        }
        return -1;
    }
};