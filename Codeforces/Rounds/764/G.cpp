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
    int n, n_components;
    vector<int> parent, rank;

    DSU(int n)
    {
        this->n = n_components = n;
        parent = vector<int>(n, -1);
        rank = vector<int>(n, 1);
    }

    int root(int a)
    {
        if (parent[a] == -1)
            return a;
        return parent[a] = root(parent[a]);
    }

    void unite(int a, int b)
    {
        int pa = root(a), pb = root(b);
        if (pa != pb)
        {
            if (rank[pa] < rank[pb])
            {
                parent[pa] = pb;
                rank[pb] += rank[pa];
            }
            else
            {
                parent[pb] = pa;
                rank[pa] += rank[pb];
            }
            n_components--;
        }
    }
};

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] > b[2];
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
        int n, m;
        cin >> n >> m;

        vector<vector<int>> v(m, vector<int>(3));
        for (int i = 0; i < m; i++)
        {
            cin >> v[i][0] >> v[i][1] >> v[i][2];
            v[i][0]--, v[i][1]--;
        }
        sort(v.begin(), v.end(), cmp);

        int ans = (1 << 30) - 1, removed = 0;
        for (int i = 29; i >= 0; i--)
        {
            DSU d(n);
            int mask = 1 << i;

            for (int j = 0; j < m; j++)
            {
                if ((v[j][2] & mask) == 0 && (removed & v[j][2]) == 0)
                {
                    d.unite(v[j][0], v[j][1]);
                }
            }
            if (d.n_components == 1)
                ans = (ans & (~mask)), removed |= mask;
        }
        cout << ans << endl;
    }
    return 0;
}