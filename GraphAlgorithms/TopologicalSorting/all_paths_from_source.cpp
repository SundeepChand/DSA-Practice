#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;

    void dfs(vector<vector<int>> &graph, int cur, vector<int> &cur_path)
    {
        int n = graph.size();

        cur_path.push_back(cur);

        if (cur == n - 1)
            ans.push_back(cur_path);
        else
            for (int nbr : graph[cur])
            {
                dfs(graph, nbr, cur_path);
            }

        cur_path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<int> cur_path;
        dfs(graph, 0, cur_path);

        return ans;
    }
};