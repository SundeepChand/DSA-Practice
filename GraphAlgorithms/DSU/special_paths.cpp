#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
    int n;
    vector<int> parent, rank;

public:
    DSU() : n(0) {}
    DSU(int n)
    {
        this->n = n;
        parent = vector<int>(n, -1);
        rank = vector<int>(n, 1);
    }

    int root(int n)
    {
        if (parent[n] == -1)
            return n;
        return parent[n] = root(parent[n]);
    }

    void Union(int u, int v)
    {
        int ru = root(u), rv = root(v);

        if (ru != rv)
        {
            if (rank[ru] < rank[rv])
            {
                parent[ru] = rv;
                rank[rv] += rank[ru];
            }
            else
            {
                parent[rv] = ru;
                rank[ru] += rank[rv];
            }
        }
    }

    bool find(int u, int v)
    {
        return (root(u) == root(v));
    }
};

bool canSolve(int n, int mid, int start, int end, vector<int> &a, vector<vector<int>> &edges)
{
    DSU d(n);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0] - 1, v = edges[i][1] - 1;
        if (abs(a[u] - a[v]) <= mid)
        {
            d.Union(u, v);
        }
    }
    return d.find(start - 1, end - 1);
}

int specialPath(int n, vector<int> &a, vector<vector<int>> &edges, int start, int end)
{
    int lb = 0, ub = 0;
    for (int i = 0; i < n; i++)
    {
        ub = max(ub, a[i]);
    }

    int ans = INT_MAX;
    while (lb <= ub)
    {
        int mid = (lb + ub) / 2;
        if (canSolve(n, mid, start, end, a, edges))
        {
            ans = mid;
            ub = mid - 1;
        }
        else
        {
            lb = mid + 1;
        }
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<int> val(n);
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    int start, end;
    cin >> start >> end;

    cout << specialPath(n, val, edges, start, end) << endl;
    return 0;
}