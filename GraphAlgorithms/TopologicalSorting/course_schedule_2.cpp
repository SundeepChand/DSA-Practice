#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool imp;

    void dfs(vector<set<int>> &adj, int cur, vector<int> &visited, vector<int> &ans)
    {
        visited[cur] = 0;

        for (int nbr : adj[cur])
        {
            if (visited[nbr] == -1)
            {
                dfs(adj, nbr, visited, ans);
            }
            else if (visited[nbr] == 0)
            {
                // Found a backedge
                imp = true;
                break;
            }
        }
        visited[cur] = 1;
        ans.push_back(cur);
    }

    vector<int> findOrderDFS(int n, vector<vector<int>> &p)
    {
        imp = false;
        vector<set<int>> adj(n, set<int>());

        for (int i = 0; i < p.size(); i++)
        {
            int u = p[i][0], v = p[i][1];
            adj[u].insert(v);
        }

        vector<int> visited(n, -1);
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == -1)
                dfs(adj, i, visited, ans);
            if (imp)
                break;
        }
        if (imp)
            return vector<int>();
        return ans;
    }

    vector<int> findLexicographicallySmallestOrder(int n, vector<vector<int>> p)
    {
        // To find the lexicographically smallest ordering use BFS by using a multiset
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n, vector<int>());

        for (int i = 0; i < p.size(); i++)
        {
            int u = p[i][0], v = p[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        vector<int> ans;
        multiset<int> q;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                q.insert(i);

        while (!q.empty())
        {
            int cur = *q.begin();
            q.erase(q.begin());
            ans.push_back(cur);

            for (int nbr : adj[cur])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                    q.insert(nbr);
            }
        }
        if (ans.size() < n)
            return vector<int>();
        return ans;
    }
};