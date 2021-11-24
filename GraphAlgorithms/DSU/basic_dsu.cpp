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

        if (pa != pb)
        {
            if (ra < rb)
            {
                v[pa] = pb;
            }
            else
            {
                v[pb] = pa;
            }
        }
    }

    bool find(int a, int b)
    {
        int ra = 0, rb = 0;
        return (root(a, ra) == root(b, rb));
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
        int r = 0;
        cout << d.root(i, r) << ", " << r << endl;
    }
    cout << endl;
    return 0;
}