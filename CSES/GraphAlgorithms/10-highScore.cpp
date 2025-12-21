#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;

#define int ll

vector<bool> visited1, visited2;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int src)
{
    visited[src] = true;
    for (int nbr : adj[src])
    {
        if (!visited[nbr])
        {
            dfs(adj, visited, nbr);
        }
    }
}

int bellmanFord(int n, int m, vector<vector<int>> &edges)
{
    vector<int> dist(n, LONG_LONG_MAX);
    dist[0] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (vector<int> v : edges)
        {
            int from = v[0], to = v[1], w = v[2];
            if (dist[from] != LONG_LONG_MAX && dist[from] + w < dist[to])
            {
                dist[to] = dist[from] + w;
            }
        }
    }

    // Check for -ve weight cycle
    bool hasCycle = false;
    for (vector<int> v : edges)
    {
        int from = v[0], to = v[1], w = v[2];
        if (dist[from] != LONG_LONG_MAX && (dist[from] + w < dist[to]) && visited1[to] && visited2[to])
        {
            hasCycle = true;
            break;
        }
    }
    if (hasCycle)
        return -1;
    return -dist[n - 1];
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

    visited1 = visited2 = vector<bool>(n, false);
    vector<vector<int>> adj1(n, vector<int>()), adj2(n, vector<int>());

    vector<vector<int>> v(m, vector<int>(3));
    for (int i = 0; i < m; i++)
    {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
        v[i][0]--, v[i][1]--;
        v[i][2] = -v[i][2];

        adj1[v[i][0]].push_back(v[i][1]);
        adj2[v[i][1]].push_back(v[i][0]);
    }

    dfs(adj1, visited1, 0);
    dfs(adj2, visited2, n - 1);
    cout << bellmanFord(n, m, v) << endl;
    return 0;
}