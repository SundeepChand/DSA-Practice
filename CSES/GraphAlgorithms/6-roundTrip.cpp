#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;

void dfs(vector<vector<int>> &adj, int cur, int par, vector<bool> &visited, vector<int> &parent, int &src, int &dest)
{
    visited[cur] = true;
    parent[cur] = par;

    if (src != -1)
        return;

    for (int nbr : adj[cur])
    {
        if (!visited[nbr])
        {
            dfs(adj, nbr, cur, visited, parent, src, dest);
        }
        else if (nbr != par)
        {
            // Cycle found
            src = nbr;
            dest = cur;
            break;
        }
    }
}

vector<int> getCycle(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    int src = -1, dest = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(adj, i, -1, visited, parent, src, dest);
        }
    }
    if (src != -1 && dest != -1)
    {
        vector<int> path;
        path.push_back(dest);
        int cur = src;
        while (cur != dest && cur != -1)
        {
            path.push_back(cur);
            cur = parent[cur];
        }
        path.push_back(cur);
        return path;
    }
    return vector<int>();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

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
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> path = getCycle(adj);
    if (path.size() <= 0)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << path.size() << endl;
        for (int x : path)
            cout << (x + 1) << " ";
        cout << endl;
    }
    return 0;
}