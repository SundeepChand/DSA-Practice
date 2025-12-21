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
        // Use a recursive implementation to easily apply path compression
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

vector<vector<int>> kruskal(int n, vector<pair<int, pair<int, int>>> &edges)
{
    int m = edges.size();
    sort(edges.begin(), edges.end());

    vector<vector<int>> ans;

    DSU d(n);
    for (int i = 0, j = 0; i < m && j < n - 1; i++)
    {
        int w = edges[i].first;
        int u = edges[i].second.first, v = edges[i].second.second;
        if (!d.find(u, v))
        {
            ans.push_back({u, v, w});
            d.Union(u, v);
            j++;
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> edges(m);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges[i] = {w, {u, v}};
    }

    vector<vector<int>> mst = kruskal(n, edges);

    long long ans = 0;
    for (int i = 0; i < mst.size(); i++)
    {
        ans += (long long)(mst[i][2]);
    }
    cout << ans << endl;
    return 0;
}