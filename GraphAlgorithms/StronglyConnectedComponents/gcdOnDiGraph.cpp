#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

void dfs1(vector<vector<int>> &adj, int src, vector<bool> &visited, vector<int> &order)
{
    visited[src] = true;
    for (int nbr : adj[src])
    {
        if (!visited[nbr])
            dfs1(adj, nbr, visited, order);
    }
    order.push_back(src);
}

vector<int> topologicalSort(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> order;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            int cur = 0;
            dfs1(adj, i, visited, order);
        }
    }
    reverse(order.begin(), order.end());
    return order;
}

void dfs2(vector<vector<int>> &adj, int i, vector<bool> &visited, int &cur, vector<int> &v)
{
    visited[i] = true;
    cur = __gcd(cur, v[i]);

    for (int nbr : adj[i])
    {
        if (!visited[nbr])
            dfs2(adj, nbr, visited, cur, v);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }

    int ans = INT_MAX;
    vector<int> order = topologicalSort(adj);
    vector<bool> visited(n, false);
    for (int i : order)
    {
        cout << "DEB: " << i + 1 << endl;
        if (!visited[i])
        {
            int cur = 0;
            dfs2(adj, i, visited, cur, v);
            ans = min(ans, cur);
        }
    }
    cout << ans << endl;
    return 0;
}