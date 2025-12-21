#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<pair<int, int>>> &adj, int u, int v, int w, bool dir = false)
{
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
{
    int n = adj.size();
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    set<pair<int, int>> s;
    s.insert({0, src});
    while (!s.empty())
    {
        auto cur = *(s.begin());
        s.erase(s.begin());

        int u = cur.second;
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first, w = adj[u][i].second;
            if (w + dist[u] < dist[v])
            {
                s.erase({dist[v], v});
                dist[v] = dist[u] + w;
                s.insert({dist[v], v});
            }
        }
    }
    return dist;
}

int main()
{
    int n = 5;
    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
    addEdge(adj, 0, 1, 1);
    addEdge(adj, 0, 2, 4);
    addEdge(adj, 0, 3, 7);
    addEdge(adj, 2, 3, 2);
    addEdge(adj, 2, 1, 1);
    addEdge(adj, 3, 4, 3);

    int src = 0;
    vector<int> dist = dijkstra(adj, src);
    for (int i = 0; i < n; i++)
    {
        cout << i << " - " << src << " = " << dist[i] << endl;
    }
    return 0;
}