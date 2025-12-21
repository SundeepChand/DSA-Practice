#include <bits/stdc++.h>
using namespace std;

// DSU using union by rank and path compression
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
        // int cur = n;
        // while (parent[cur] != -1)
        // {
        //     cur = parent[cur];
        // }
        // return cur;

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

int main()
{
    int n = 10;
    DSU d(n);
    d.Union(0, 9);
    d.Union(1, 5);
    d.Union(1, 2);
    d.Union(2, 9);
    d.Union(3, 6);
    d.Union(6, 7);

    cout << d.find(3, 4) << endl;
    cout << d.find(9, 1) << endl;
    for (int i = 0; i < n; i++)
    {
        cout << d.root(i) << ", ";
    }
    cout << endl;
    return 0;
}