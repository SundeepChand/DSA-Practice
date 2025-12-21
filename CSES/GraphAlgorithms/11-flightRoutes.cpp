#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;

vector<ll> dijkstra(vector<vector<pair<int, ll>>> &adj, int src)
{
    int n = adj.size();
    vector<ll> dist(n, LONG_LONG_MAX);
    dist[src] = 0;

    set<pair<ll, int>> s;
    s.insert({0, src});
    while (!s.empty())
    {
        auto cur = *(s.begin());
        s.erase(s.begin());

        ll d = cur.first;
        int u = cur.second;
        for (auto nbr : adj[u])
        {
            int v = nbr.first;
            ll w = nbr.second;
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ll n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> adj1(n, vector<pair<int, ll>>());
    vector<vector<pair<int, ll>>> adj2(n, vector<pair<int, ll>>());
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj1[u].push_back({v, w});
        adj2[v].push_back({u, w});
    }

    vector<ll> d1, d2;
    d1 = dijkstra(adj1, 0);
    d2 = dijkstra(adj2, n - 1);

    ll ans = LONG_LONG_MAX;
    for (int i = 0; i < n; i++)
    {
        for (auto nbr : adj1[i])
        {
            int u = i, v = nbr.first, w = nbr.second;
            if (d1[u] != LONG_LONG_MAX && d2[v] != LONG_LONG_MAX)
                ans = min(ans, d1[u] + d2[v] + w / 2);
        }
    }
    cout << ans << endl;

    return 0;
}