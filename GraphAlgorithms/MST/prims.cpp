#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> prim(vector<vector<pair<int, int>>> &adj)
{
    int n = adj.size();
    int src = 0;
    vector<vector<int>> ans;

    priority_queue<pair<int, pair<int, int>>> pq;
    for (pair<int, int> nbrs : adj[src])
    {
        pq.push({-nbrs.second, {src, nbrs.first}});
    }

    vector<bool> visited(n, false);
    visited[src] = true;
    while (!pq.empty())
    {
        pair<int, pair<int, int>> cur = pq.top();
        pq.pop();

        int u = cur.second.first, v = cur.second.second;
        if (!visited[v])
        {
            ans.push_back({u, v, -cur.first});
            visited[v] = true;
            for (pair<int, int> nbrs : adj[v])
            {
                if (!visited[nbrs.first])
                    pq.push({-nbrs.second, {v, nbrs.first}});
            }
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<vector<int>> mst = prim(adj);

    long long ans = 0;
    for (int i = 0; i < mst.size(); i++)
    {
        ans += (long long)(mst[i][2]);
    }
    cout << ans << endl;
    return 0;
}