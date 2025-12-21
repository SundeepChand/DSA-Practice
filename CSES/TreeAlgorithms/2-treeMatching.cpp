#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

void dfs(vector<vector<int>> &adj, int src, int par, vector<bool> &paired, int &ans)
{
    bool isLeaf = true;
    for (int nbr : adj[src])
    {
        if (nbr != par)
        {
            dfs(adj, nbr, src, paired, ans);
            isLeaf = false;
        }
    }
    if (par != -1 && isLeaf && !paired[par])
    {
        ans++;
        paired[src] = paired[par] = true;
    }
    else if (par != -1 && !paired[src] && !paired[par])
    {
        ans++;
        paired[src] = paired[par] = true;
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

    int n;
    cin >> n;

    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = 0;
    vector<bool> paired(n, false);
    dfs(adj, 0, -1, paired, ans);
    cout << ans << endl;
    return 0;
}