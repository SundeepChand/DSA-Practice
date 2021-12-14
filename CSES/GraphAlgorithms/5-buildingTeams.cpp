#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;

vector<int> isBipartite(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> color(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            queue<int> q;
            q.push(i);
            color[i] = 0;
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();

                for (int nbr : adj[cur])
                {
                    if (color[nbr] == -1)
                    {
                        q.push(nbr);
                        color[nbr] = !color[cur];
                    }
                    else if (color[nbr] == color[cur])
                        return vector<int>();
                }
            }
        }
    }
    return color;
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
        int u, v;
        cin >> u >> v;

        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Check if the graph is bipartite
    vector<int> ans = isBipartite(adj);
    if (ans.size() == 0)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        for (int x : ans)
        {
            cout << (x + 1) << " ";
        }
        cout << endl;
    }
    return 0;
}