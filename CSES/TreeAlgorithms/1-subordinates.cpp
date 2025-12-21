#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int dfs(vector<vector<int>> &adj, int src, int par, vector<int> &ans)
{
    for (int nbr : adj[src])
        if (nbr != par)
            ans[src] += dfs(adj, nbr, src, ans);
    return ans[src] + 1;
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
        int p;
        cin >> p;
        p--;
        adj[i + 1].push_back(p);
        adj[p].push_back(i + 1);
    }

    vector<int> ans(n, 0);
    dfs(adj, 0, -1, ans);
    for (int x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}