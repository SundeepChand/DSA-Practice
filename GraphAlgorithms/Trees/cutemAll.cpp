#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int dfs(vector<vector<int>> &adj, int src, int par, int &ans)
{
    int cur = 1;
    for (int nbr : adj[src])
    {
        if (nbr != par)
        {
            cur += dfs(adj, nbr, src, ans);
        }
    }
    if (par != -1 && cur % 2 == 0)
    {
        ans++;
        cur = 0;
    }
    return cur;
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
    for (int i = 0; i < (n - 1); i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (n % 2 == 1)
    {
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    dfs(adj, 0, -1, ans);
    cout << ans << endl;
    return 0;
}