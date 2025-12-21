#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;

#define int ll

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
{
    int n = adj.size();
    vector<int> dist(n, LONG_LONG_MAX);
    dist[src] = 0;
    set<pair<int, int>> s;
    s.insert({0, src});
    while (!s.empty())
    {
        auto cur = *(s.begin());
        s.erase(s.begin());

        int u = cur.second, d = cur.first;
        for (pair<int, int> nbr : adj[u])
        {
            int v = nbr.first, w = nbr.second;
            if (d + w < dist[v])
            {
                s.erase({dist[v], v});
                dist[v] = d + w;
                s.insert({dist[v], v});
            }
        }
    }
    return dist;
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

    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
    }

    vector<int> dist = dijkstra(adj, 0);
    for (auto x : dist)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}