#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

void dfs(vector<vector<int>> &adj, int src, int par, vector<int> &tour, vector<int> &it)
{
    for (int i = it[src]; i < adj[src].size(); i = it[src])
    {
        int nbr = adj[src][it[src]];
        it[src]++;
        if (nbr != par)
            dfs(adj, nbr, src, tour, it);
    }
    tour.push_back(src);
}

vector<int> getEulerTour(vector<vector<int>> &adj)
{
    int n = adj.size();

    vector<int> deg(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int nbr : adj[i])
            deg[nbr]++;
    }

    int oddCtr = 0, evenCtr = 0, odd = -1, even = -1;
    for (int i = 0; i < n; i++)
    {
        if (deg[i] % 2 == 1)
            oddCtr++, odd = i;
        else
            evenCtr++, even = i;
    }
    if (oddCtr != 0 and oddCtr != 2)
        return vector<int>();

    vector<int> tour;
    vector<int> it(n, 0);
    dfs(adj, oddCtr != 0 ? odd : even, -1, tour, it);
    reverse(tour.begin(), tour.end());
    return tour;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n, vector<int>());

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> eulerTour = getEulerTour(adj);
    if (eulerTour.size() == 0)
        cout << "No Euler Tour exist." << endl;
    else
    {
        cout << "Following is the euler tour: " << endl;
        for (int x : eulerTour)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}