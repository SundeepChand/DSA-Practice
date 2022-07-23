#include <bits/stdc++.h>
using namespace std;

int ans = 0;

bool hasMaj(vector<int> &v)
{
    int n = v.size();

    unordered_map<int, int> u;
    for (int x : v)
    {
        u[x]++;
        if (u[x] >= ceil(double(n) / 2.0))
            return true;
    }
    return false;
}

void dfs(vector<vector<int>> &adj, int src, int par, vector<int> &cur, vector<int> &C)
{
    cur.push_back(src);
    // This can be optimised by passing a map
    if (hasMaj(cur))
        ans++;

    for (auto nbr : adj[src])
    {
        if (nbr != par)
            dfs(adj, nbr, src, cur, C);
    }

    cur.pop_back();
}

int solve(int n, vector<int> &C, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(n, vector<int>());

    for (auto e : edges)
    {
        int u = e[0] - 1, v = e[1] - 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> cur;
    ans = 0;
    unordered_map<int, int> u;
    dfs(adj, 0, -1, cur, C);
    return ans;
}

int main()
{
    return 0;
}