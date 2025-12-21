#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;

class DSU
{
public:
    vector<int> parent, rank;
    int n, n_conn;

    DSU(int n)
    {
        this->n = n;
        parent = vector<int>(n, -1);
        rank = vector<int>(n, 1);
        n_conn = n;
    }
    int root(int n)
    {
        if (parent[n] == -1)
            return n;
        return parent[n] = root(parent[n]);
    }
    void Union(int a, int b)
    {
        int pa = root(a), pb = root(b);
        if (pa != pb)
        {
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
            n_conn--;
        }
    }
    bool find(int a, int b)
    {
        int pa = root(a), pb = root(b);
        return pa == pb;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    DSU d(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        d.Union(a, b);
    }

    vector<pair<int, int>> ans;
    for (int i = 1; i < n; i++)
    {
        if (!d.find(0, i))
        {
            ans.push_back({1, i + 1});
            d.Union(0, i);
            if (d.n_conn >= n - 1)
                break;
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans)
    {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}