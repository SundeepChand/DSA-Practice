#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
{
    int n = adj.size();
    vector<int> dist(n, INT_MAX), parent(n, -1);
    dist[src] = 0;

    set<pair<int, int>> s;
    s.insert({0, src});
    while (!s.empty())
    {
        auto cur = *(s.begin());
        s.erase(s.begin());

        int u = cur.second, d = cur.first;
        for (auto nbr : adj[u])
        {
            int v = nbr.first, w = nbr.second;
            if (d + w < dist[v])
            {
                s.erase({dist[v], v});
                dist[v] = d + w;
                parent[v] = u;
                s.insert({dist[v], v});
            }
        }
    }
    return parent;
}

vector<int> travelByCar(int n, int l, vector<vector<int>> edges, vector<vector<int>> queries)
{
    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
    vector<vector<int>> cost(n, vector<int>(n, -1));

    for (auto x : edges)
    {
        int u = x[0] - 1, v = x[1] - 1, w = x[2];
        if (w <= l)
        {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            cost[u][v] = cost[v][u] = w;
        }
    }

    vector<vector<int>> parent(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = dijkstra(adj, i);
    }

    vector<int> ans(queries.size());
    for (int i = 0; i < queries.size(); i++)
    {
        int u = queries[i][0] - 1, v = queries[i][1] - 1;
        vector<int> path;
        int cur = v;
        while (cur != -1)
        {
            path.push_back(cur);
            cur = parent[u][cur];
        }
        if (path.size() <= 1)
        {
            ans[i] = -1;
        }
        else
        {
            reverse(path.begin(), path.end());
            int temp_ans = 0, cur_fuel = l;
            for (int i = 0; i < path.size() - 1; i++)
            {
                int c = cost[path[i]][path[i + 1]];
                if (c > cur_fuel)
                {
                    cur_fuel = l;
                    temp_ans++;
                }
                cur_fuel -= c;
            }
            ans[i] = temp_ans;
        }
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m, l, q;
    cin >> n >> m >> l;

    vector<vector<int>> edges(m, vector<int>(3));
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    cin >> q;
    vector<vector<int>> queries(q, vector<int>(2));
    for (int i = 0; i < q; i++)
    {
        cin >> queries[i][0] >> queries[i][1];
    }

    vector<int> ans = travelByCar(n, l, edges, queries);
    for (auto x : ans)
    {
        cout << x << endl;
    }
    return 0;
}