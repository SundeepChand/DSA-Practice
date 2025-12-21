#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

class DSU
{
public:
    int n, npairs;
    vector<int> parent, rank;

    DSU(int n)
    {
        this->n = n, npairs = 0;
        parent = vector<int>(n, -1);
        rank = vector<int>(n, 1);
    }

    int root(int v)
    {
        if (parent[v] == -1)
            return v;
        return parent[v] = root(parent[v]);
    }

    void unite(int u, int v)
    {
        int pa = root(u), pb = root(v);
        if (pa != pb)
        {
            npairs -= (rank[pa] * (rank[pa] - 1)) / 2;
            npairs -= (rank[pb] * (rank[pb] - 1)) / 2;
            npairs += ((rank[pa] + rank[pb]) * (rank[pa] + rank[pb] - 1)) / 2;
            if (rank[pa] > rank[pb])
            {
                parent[pb] = pa;
                rank[pa] += rank[pb];
            }
            else
            {
                parent[pa] = pb;
                rank[pb] += rank[pa];
            }
        }
    }

    int value()
    {
        return npairs;
    }
};

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

    vector<vector<int>> edges(n, vector<int>(3));
    for (int i = 0; i < n - 1; i++)
    {
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
        edges[i][1]--, edges[i][2]--;
    }
    sort(edges.begin(), edges.end());

    map<int, int> ans;
    DSU d(n);
    int sz = edges.size();
    for (int i = 0; i < sz; i++)
    {
        while (i < sz - 1 && edges[i][0] == edges[i + 1][0])
        {
            d.unite(edges[i][1], edges[i][2]);
            i++;
        }
        if (i <= sz - 1)
            d.unite(edges[i][1], edges[i][2]);
        ans[edges[i][0]] = d.value();
    }

    for (int i = 0; i < m; i++)
    {
        int q;
        cin >> q;
        auto it = ans.upper_bound(q);
        if (ans.size() == 0 || it == ans.begin())
            cout << 0;
        else
        {
            it--;
            cout << it->second;
        }
        cout << " ";
    }
    return 0;
}