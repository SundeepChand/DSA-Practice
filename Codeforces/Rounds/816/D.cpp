#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, q;
    cin >> n >> q;

    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());

    vector<vector<int>> edges(q, vector<int>(3));

    for (int i = 0; i < q; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        if (u > v)
            swap(u, v);

        edges[i][0] = u, edges[i][1] = v, edges[i][2] = w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<vector<bool>> ans(n, vector<bool>(32, 1));

    for (int i = 0; i < 32; i++)
    {
        int ansIdx = 31 - i;
        for (int j = 0; j < q; j++)
        {
            if (!((edges[j][2] >> i) & 1))
            {
                int u = edges[j][0], v = edges[j][1];
                ans[u][ansIdx] = ans[v][ansIdx] = 0;
            }
        }

        for (int u = 0; u < n; u++)
        {
            if (ans[u][ansIdx] == 0)
                continue;

            ans[u][ansIdx] = 0;
            bool flag = false;
            for (auto nbr : adj[u])
            {
                int v = nbr.first, w = nbr.second;
                if ((ans[u][ansIdx] | ans[v][ansIdx]) != ((w >> i) & 1))
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
                ans[u][ansIdx] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int val = 0;
        for (int j = 0; j < 32; j++)
        {
            val = 2 * val + ans[i][j];
        }
        cout << val << " ";
    }
    cout << endl;

    return 0;
}