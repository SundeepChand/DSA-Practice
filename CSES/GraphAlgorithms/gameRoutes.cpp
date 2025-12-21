#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int gameRoutes(int n, vector<vector<int>> v)
{
    vector<vector<int>> adj(n, vector<int>()), comp(n, vector<int>());
    vector<int> indeg(n, 0);
    int m = v.size();
    for (int i = 0; i < m; i++)
    {
        int u = v[i][0] - 1, t = v[i][1] - 1;
        adj[u].push_back(t);
        comp[t].push_back(u);
        indeg[t]++;
    }

    queue<int> q;
    vector<int> dist(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
            q.push(i);
    }
    dist[0] = 1;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        // Calculate the no of ways for cur
        for (int nbr : comp[cur])
        {
            dist[cur] = (dist[cur] + dist[nbr]) % MOD;
        }

        // Add the new nodes in the topological order
        for (int nbr : adj[cur])
        {
            indeg[nbr]--;
            if (indeg[nbr] == 0)
                q.push(nbr);
        }
    }
    return dist[n - 1];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> v[i][0] >> v[i][1];
    }

    cout << gameRoutes(n, v) << endl;
}