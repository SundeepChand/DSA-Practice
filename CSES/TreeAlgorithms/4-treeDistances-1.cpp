#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int dfs(vector<vector<int>> &adj, int src, int parent, int d, vector<int> &dist)
{
    dist[src] = max(dist[src], d);
    int ans = src;
    for (int nbr : adj[src])
    {
        if (nbr != parent)
        {
            int cur = dfs(adj, nbr, src, d + 1, dist);
            if (dist[cur] > dist[ans])
                ans = cur;
        }
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist = vector<int>(n, 0);
    int endPoint1 = dfs(adj, 0, -1, 0, dist);
    dist = vector<int>(n, 0);
    int endPoint2 = dfs(adj, endPoint1, -1, 0, dist);
    dfs(adj, endPoint2, -1, 0, dist);

    for (int x : dist)
        cout << x << " ";
    return 0;
}