#include <bits/stdc++.h>
using namespace std;

bool validBfs(int n, vector<int> &arr, vector<vector<int>> &edges)
{
    if (arr[0] != 1)
        return 0;
    vector<set<int>> adj(n);
    vector<int> nnbrs(n, 0);

    for (vector<int> x : edges)
    {
        int u = x[0] - 1, v = x[1] - 1;
        adj[u].insert(v);
        adj[v].insert(u);
        nnbrs[u]++, nnbrs[v]++;
    }

    queue<int> q;
    vector<bool> visited(n, 0);
    int src = arr[0] - 1;
    visited[src] = 1;
    q.push(src);

    int i = 1;
    while (i < n && !q.empty())
    {
        int cur = q.front();
        q.pop();
        int cur_nnbrs = nnbrs[cur];
        for (int j = 0; j < cur_nnbrs; j++)
        {
            int u = arr[i] - 1;
            i++;
            if (u >= n || visited[u] || adj[cur].find(u) == adj[cur].end())
            {
                return false;
            }
            else
            {
                visited[u] = 1;
                q.push(u);
                nnbrs[u]--;
                nnbrs[cur]--;
            }
        }
    }
    bool allVisited = (i >= n);
    for (int i = 0; i < n; i++)
    {
        allVisited = allVisited && visited[i];
    }
    return allVisited;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    vector<vector<int>> edges(n - 1, vector<int>(2));
    for (int i = 0; i < n - 1; i++)
        cin >> edges[i][0] >> edges[i][1];

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // 1 2 3 4 5 7 6 8
    // 1 3 2 4 7 6 5 8

    bool ans = validBfs(n, arr, edges);
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}