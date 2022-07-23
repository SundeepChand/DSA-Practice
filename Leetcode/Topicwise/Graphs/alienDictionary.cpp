#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    pair<char, char> cmp(string u, string v)
    {
        int n = u.size(), m = v.size();
        int i, j;
        for (i = 0, j = 0; i < n and j < m and u[i] == v[j]; i++, j++)
            ;
        if (i == n or j == m)
            return {'\0', '\0'};
        return {u[i], v[j]};
    }

    void dfs(vector<set<int>> &adj, int src, vector<int> &res, vector<bool> &visited)
    {
        visited[src] = true;

        for (auto nbr : adj[src])
        {
            if (!visited[nbr])
                dfs(adj, nbr, res, visited);
        }
        res.push_back(src);
    }

    string topoSort(vector<set<int>> &adj, vector<char> &revmap)
    {
        int n = adj.size();

        vector<int> res;

        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
                dfs(adj, i, res, visited);
        }

        string ans = "";
        for (int i = n - 1; i >= 0; i--)
        {
            ans.push_back(revmap[res[i]]);
        }
        return ans;
    }

    string findOrder(string dict[], int N, int K)
    {

        map<char, int> m;
        vector<char> revmap;

        int ctr = 0;
        vector<set<int>> adj(K, set<int>());

        for (int i = 1; i < N; i++)
        {
            pair<char, char> cmpRes = cmp(dict[i - 1], dict[i]);
            char u = cmpRes.first, v = cmpRes.second;
            if (u == '\0')
                continue;

            if (m.find(u) == m.end())
            {
                m[u] = ctr++;
                revmap.push_back(u);
            }
            if (m.find(v) == m.end())
            {
                m[v] = ctr++;
                revmap.push_back(v);
            }
            adj[m[u]].insert(m[v]);
        }
        for (int i = 0; i < N; i++)
        {
            for (char c : dict[i])
            {
                if (m.find(c) == m.end())
                {
                    m[c] = ctr++;
                    revmap.push_back(c);
                }
            }
        }

        return topoSort(adj, revmap);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;

    string dict[n];
    for (int i = 0; i < n; i++)
        cin >> dict[i];

    Solution s;
    cout << s.findOrder(dict, n, k) << endl;
    return 0;
}