#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

void solve(vector<vector<vector<int>>> &adj, int src, int par, int atot, vector<int> &bi, int i, int btot, vector<int> &ans)
{
    // while (i < bi.size() and btot < atot)
    // {
    //     if (btot + bi[i] > atot)
    //         break;
    //     btot += bi[i];
    //     i++;
    // }
    // cout << "DEB: " << src << ", " << atot << " -> ";
    // for (auto x : bi)
    //     cout << x << " ";
    // cout << endl;
    bi.push_back(btot);

    auto idx = upper_bound(bi.begin(), bi.end(), atot) - bi.begin();
    ans[src] = idx - 1;

    for (auto nbr : adj[src])
    {
        int v = nbr[0], a = nbr[1], b = nbr[2];
        if (v != par)
        {
            solve(adj, v, src, atot + a, bi, i, btot + b, ans);
        }
    }
    bi.pop_back();
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
        // cout << "DEB0: " << n << endl;

        vector<vector<vector<int>>> adj(n, vector<vector<int>>());

        // cout << "HEre0" << endl;
        for (int i = 1; i < n; i++)
        {
            int u = i, v, a, b;
            cin >> v >> a >> b;
            v--;
            // cout << "DEB: " << u << " " << v << endl;
            adj[u].push_back({v, a, b});
            adj[v].push_back({u, a, b});
        }
        // cout << "HEre" << endl;

        vector<int> ans(n);
        ans[0] = -1;
        vector<int> bi;
        solve(adj, 0, -1, 0, bi, 0, 0, ans);

        for (int i = 1; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}