#include <bits/stdc++.h>
using namespace std;

int n, m, q;

int serialise(int i, int j)
{
    return i * m + j;
}

class DSU
{
public:
    int n;
    vector<int> par, rank, cont;

    DSU(int n)
    {
        this->n = n;
        par = vector<int>(n, -1);
        rank = cont = vector<int>(n, 1);
    }

    int root(int u)
    {
        if (par[u] == -1)
            return u;
        return par[u] = root(par[u]);
    }

    void Union(int u, int v)
    {
        int pu = root(u), pv = root(v);
        if (pu != pv)
        {
            if (rank[pu] < rank[pv])
            {
                par[pu] = pv;
                rank[pv] += rank[pu];
            }
            else
            {
                par[pv] = pu;
                rank[pu] += rank[pv];
            }
        }
    }

    void initCountries(vector<vector<int>> &grid)
    {
        cont = rank;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (!grid[i][j])
                {
                    cont[serialise(i, j)] = 0;
                }
            }
        }
    }

    int getConnCountries(int u)
    {
        int pu = root(u);
        int val = cont[pu];
        cont[pu] = 0;
        return val;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;

    vector<vector<int>> grid(n, vector<int>(m));

    int countries = 0;

    DSU d(n * m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j])
            {
                countries += grid[i][j];
                if (i > 0 and grid[i - 1][j])
                    d.Union(serialise(i - 1, j), serialise(i, j));
                if (j > 0 and grid[i][j - 1])
                    d.Union(serialise(i, j - 1), serialise(i, j));
            }
        }
    }
    d.initCountries(grid);

    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;

        int destCountries = d.getConnCountries(serialise(x, y));
        countries -= destCountries;
        cout << countries << '\n';
    }

    return 0;
}