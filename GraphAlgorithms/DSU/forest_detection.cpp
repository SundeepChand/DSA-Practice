// Detect cycle in a given undirected graph
#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
    int n;
    vector<int> v;

public:
    DSU() : n(0) {}
    DSU(int n)
    {
        this->n = n;
        v = vector<int>(n, -1);
    }

    int root(int a, int &r)
    {
        int cur = a;
        while (v[cur] != -1)
        {
            r++;
            cur = v[cur];
        }
        return cur;
    }

    void Union(int a, int b)
    {
        // Find ranks of both the components.
        int ra = 0;
        int pa = root(a, ra);

        int rb = 0;
        int pb = root(b, rb);

        if (ra < rb)
        {
            v[pa] = pb;
        }
        else
        {
            v[pb] = pa;
        }
    }

    bool find(int a, int b)
    {
        int ra = 0, rb = 0;
        return (root(a, ra) == root(b, rb));
    }
};

bool solve(vector<vector<int>> edges)
{
    DSU d(100001);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0], v = edges[i][1];
        if (d.find(u, v))
            return false;
        d.Union(u, v);
    }
    return true;
}