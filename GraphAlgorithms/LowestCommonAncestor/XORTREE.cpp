#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

vector<int> xp;

void dfs(vector<vector<pair<int, int>>> &adj, int src, int par, int x)
{
    xp[src] = x;
    for (auto nbr : adj[src])
    {
        int v = nbr.first, w = nbr.second;
        if (v != par)
            dfs(adj, v, src, x ^ w);
    }
}

int getXorSum()
{
    // Calculate the sum of pairs of xor in O(n)
    int n = xp.size();
    vector<int> ctr(61, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 61; j++)
        {
            if (xp[i] & (1LL << j))
                ctr[j]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < ctr.size(); i++)
    {
        int x = ctr[i] % MOD, y = (n - ctr[i]) % MOD;
        ans = (ans + ((((x * y) % MOD) * ((1LL << i) % MOD)) % MOD)) % MOD;
    }
    return ans;
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

    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    xp = vector<int>(n);
    xp[0] = 0;
    dfs(adj, 0, -1, 0);

    cout << getXorSum() << endl;

    return 0;
}