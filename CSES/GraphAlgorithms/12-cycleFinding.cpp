#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;

#define int ll

#define inf (1LL << 62)

vector<int> bellman_ford(vector<vector<int>> &edges, int n)
{
    vector<int> dist(n, inf), parent(n, -1);
    dist[0] = 0;

    int end = -1;
    for (int i = 0; i < n; i++)
    {
        end = -1;
        for (auto e : edges)
        {
            int u = e[0], v = e[1], w = e[2];
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                end = v;
            }
        }
    }

    vector<int> cycle;
    if (end == -1)
        return cycle;

    for (int i = 0; i < n; i++)
    {
        end = parent[end];
    }
    for (int cur = end;; cur = parent[cur])
    {
        cycle.push_back(cur);
        if (cycle.size() > 1 && cur == end)
            break;
    }
    reverse(cycle.begin(), cycle.end());

    return cycle;
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

    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.push_back({u, v, w});
    }

    vector<int> cycle = bellman_ford(edges, n);
    if (cycle.size() == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        for (auto x : cycle)
            cout << (x + 1) << " ";
        cout << endl;
    }
    return 0;
}