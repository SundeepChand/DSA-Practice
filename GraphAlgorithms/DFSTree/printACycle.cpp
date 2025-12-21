#include <bits/stdc++.h>
using namespace std;

int dest = -1;
void printACycle(vector<vector<int>> &adj, int src, int par, vector<int> &vis)
{
    vis[src] = 1;
    for (int nbr : adj[src])
    {
        if (vis[nbr] == 0)
            printACycle(adj, nbr, src, vis);
        else if (vis[nbr] == 1 && nbr != par)
        {
            dest = nbr;
            cout << nbr << " ";
            break;
        }
        if (dest != -1)
            break;
    }
    if (dest != -1 && vis[dest] == 1)
    {
        cout << src << " ";
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
    }

    vector<int> vis(n, 0);
    printACycle(adj, 3, -1, vis);
    return 0;
}