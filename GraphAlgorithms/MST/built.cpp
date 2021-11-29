#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}

int mst(int n, vector<vector<pair<int, int>>> &adj)
{
    int src = 0;
    vector<bool> visited(n, false);
    visited[src] = true;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto x : adj[src])
    {
        pq.push({x.second, x.first});
    }

    int ans = 0;
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        if (visited[cur.second])
            continue;
        ans += cur.first;

        visited[cur.second] = true;
        for (auto x : adj[cur.second])
        {
            if (!visited[x.first])
            {
                pq.push({x.second, x.first});
            }
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
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1];
        v[i][2] = i;
    }

    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
    sort(v.begin(), v.end());
    for (int i = 1; i < n; i++)
    {
        int t = v[i - 1][2], u = v[i][2];
        adj[t].push_back({u, v[i][0] - v[i - 1][0]});
        adj[u].push_back({t, v[i][0] - v[i - 1][0]});
    }

    sort(v.begin(), v.end(), cmp);
    for (int i = 1; i < n; i++)
    {
        int t = v[i - 1][2], u = v[i][2];
        adj[t].push_back({u, v[i][1] - v[i - 1][1]});
        adj[u].push_back({t, v[i][1] - v[i - 1][1]});
    }

    cout << mst(n, adj) << endl;
    return 0;
}