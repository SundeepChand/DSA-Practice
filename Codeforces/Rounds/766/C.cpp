#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

map<vector<int>, int> m;
void dfs(vector<vector<int>> &adj, int src, int par, int val)
{
    for (int nbr : adj[src])
    {
        if (nbr != par)
        {
            m[{src, nbr}] = m[{nbr, src}] = val;
            val = !val;
            dfs(adj, nbr, src, val);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<int>> adj(n, vector<int>());
        vector<int> deg(n, 0);
        vector<vector<int>> edges;
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++, deg[v]++;
            edges.push_back({u, v});
        }
        bool flag = false;
        int src = 0;
        for (int i = 0; i < n; i++)
        {
            if (deg[i] > 2)
            {
                flag = true;
                break;
            }
            else
                src = i;
        }
        if (flag)
        {
            cout << -1 << endl;
            continue;
        }
        dfs(adj, src, -1, 0);
        for (int i = 0; i < n - 1; i++)
        {
            cout << (m[{edges[i][0], edges[i][1]}] + 2) << " ";
        }
        cout << endl;
    }
    return 0;
}