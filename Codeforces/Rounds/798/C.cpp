#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

void getChildrenCount(vector<vector<int>> &adj, int src, int par, vector<int> &children)
{
    for (int nbr : adj[src])
    {
        if (nbr != par)
        {
            getChildrenCount(adj, nbr, src, children);
            children[src] += 1 + children[nbr];
        }
    }
}

int solve(vector<vector<int>> &adj, int src, int par, vector<int> &children)
{
    int left = -1, right = -1;
    for (int nbr : adj[src])
    {
        if (nbr != par)
        {
            if (left == -1)
                left = nbr;
            else
                right = nbr;
        }
    }

    if (left == -1 and right == -1)
        return 0;

    if (left == -1 or right == -1)
    {
        for (int nbr : adj[src])
        {
            if (nbr != par)
            {
                return children[nbr];
            }
        }
    }

    int ans = max(
        children[left] + solve(adj, right, src, children),
        children[right] + solve(adj, left, src, children));
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

    int t;
    cin >> t;

    while (t--)
    {
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

        vector<int> children(n, 0);
        getChildrenCount(adj, 0, -1, children);

        cout << solve(adj, 0, -1, children) << endl;
    }
    return 0;
}