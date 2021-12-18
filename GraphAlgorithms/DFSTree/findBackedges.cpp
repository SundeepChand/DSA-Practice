#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, int src, int par, vector<int> &vis)
{
    vis[src] = 1;
    for (int nbr : adj[src])
    {
        if (vis[nbr] == 0)
            dfs(adj, nbr, src, vis);
        else if (nbr != par && vis[nbr] == 1)
            cout << src << " " << nbr << endl; // Back edge
    }
    vis[src] = 2;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n, 0);
    dfs(adj, 0, -1, vis);
    return 0;
}