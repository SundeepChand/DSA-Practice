#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

pair<int, int> solve(vector<vector<int>> &adj, int src, int par)
{
    int maxDepth = 0, maxDiam = 0;
    for (int nbr : adj[src])
    {
        if (nbr != par)
        {
            pair<int, int> cur = solve(adj, nbr, src);
            maxDiam = max({maxDiam, cur.second, cur.first + maxDepth + 1});
            maxDepth = max(maxDepth, cur.first + 1);
        }
    }
    return {maxDepth, maxDiam};
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << solve(adj, 0, -1).second;
    return 0;
}