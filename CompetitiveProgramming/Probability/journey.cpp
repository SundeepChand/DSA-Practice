// https://codeforces.com/problemset/problem/839/C
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int long double

int solve(vector<vector<int>> &adj, int src, int par)
{
    if (adj[src].size() == 1)
    {
        return 0;
    }
    int ans = 0;
    for (auto nbr : adj[src])
    {
        if (nbr != par)
        {
            ans += solve(adj, nbr, src);
        }
    }
    int prob = 1.0 / (adj[src].size() - 1);
    ans *= prob;
    return ans + 1;
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
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    adj[0].push_back(-1);

    int ans = solve(adj, 0, -1);
    cout.setf(ios::fixed);
    cout << setprecision(15) << ans << endl;
    return 0;
}