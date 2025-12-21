#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>> &adj, int start, int end)
{
    int n = adj.size();

    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int x : adj[cur])
        {
            if (!visited[x])
            {
                q.push(x);
                visited[x] = true;
                parent[x] = cur;
            }
        }
    }

    vector<int> path;
    int cur = end;
    path.push_back(cur);
    while (parent[cur] != -1)
    {
        cur = parent[cur];
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> path = bfs(adj, 0, n - 1);
    if (path.size() > 1)
    {
        cout << path.size() << endl;
        for (auto x : path)
            cout << (x + 1) << " ";
        cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}