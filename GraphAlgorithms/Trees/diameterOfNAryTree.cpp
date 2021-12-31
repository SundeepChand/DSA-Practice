#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

pair<int, int> getDiam(vector<vector<int>> &adj, int src, int par)
{
    int deepLen = 0, diam = 0;
    for (int nbr : adj[src])
    {
        if (nbr != par)
        {
            auto cur = getDiam(adj, nbr, src);
            diam = max(diam, max(cur.second, cur.first + deepLen + 1));
            deepLen = max(deepLen, cur.first + 1);
        }
    }
    return {deepLen, diam};
}

int solve(vector<int> &A)
{
    int n = A.size();
    vector<vector<int>> adj(n, vector<int>());

    for (int i = 0; i < n; i++)
    {
        if (A[i] != -1)
        {
            adj[i].push_back(A[i]);
            adj[A[i]].push_back(i);
        }
    }

    return getDiam(adj, 0, -1).second;
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

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
    }
    return 0;
}