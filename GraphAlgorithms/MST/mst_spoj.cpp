#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// ll prim(vector<vector<pair<int, int>>> &adj)
// {
//     int n = adj.size();
//     int src = 0;
//     ll ans = 0;

//     priority_queue<pair<int, int>> pq;
//     for (pair<int, int> nbrs : adj[src])
//     {
//         pq.push({-nbrs.second, nbrs.first});
//     }

//     vector<bool> visited(n, false);
//     visited[src] = true;
//     while (!pq.empty())
//     {
//         pair<int, int> cur = pq.top();
//         pq.pop();

//         int w = -cur.first, v = cur.second;
//         if (!visited[v])
//         {
//             ans += (long long)(w);
//             visited[v] = true;
//             for (pair<int, int> nbrs : adj[v])
//             {
//                 if (!visited[nbrs.first])
//                     pq.push({-nbrs.second, nbrs.first});
//             }
//         }
//     }
//     return ans;
// }

class DSU
{
private:
    int n;
    vector<int> parent, rank;

public:
    DSU() : n(0) {}
    DSU(int n)
    {
        this->n = n;
        parent = vector<int>(n, -1);
        rank = vector<int>(n, 1);
    }

    int root(int n)
    {
        // Use a recursive implementation to easily apply path compression
        if (parent[n] == -1)
            return n;
        return parent[n] = root(parent[n]);
    }

    void Union(int u, int v)
    {
        int ru = root(u), rv = root(v);

        if (ru != rv)
        {
            if (rank[ru] < rank[rv])
            {
                parent[ru] = rv;
                rank[rv] += rank[ru];
            }
            else
            {
                parent[rv] = ru;
                rank[ru] += rank[rv];
            }
        }
    }

    bool find(int u, int v)
    {
        return (root(u) == root(v));
    }
};

ll kruskal(int n, vector<pair<int, pair<int, int>>> &edges)
{
    int m = edges.size();
    sort(edges.begin(), edges.end());

    ll ans = 0;

    DSU d(n);
    for (int i = 0, j = 0; i < m && j < n - 1; i++)
    {
        ll w = edges[i].first;
        int u = edges[i].second.first, v = edges[i].second.second;
        if (!d.find(u, v))
        {
            ans += w;
            d.Union(u, v);
            j++;
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> edges(m);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges[i] = {w, {u, v}};
    }

    cout << kruskal(n, edges) << endl;
    return 0;
}