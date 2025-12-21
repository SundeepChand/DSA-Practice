#include <bits/stdc++.h>
using namespace std;

class Bitset
{
public:
    typedef long long ll;
    vector<ll> v;
    int n, size;
    ll mask;
    int ones;
    int prune;
    Bitset(int size)
    {
        n = ceil(size / 64.0);
        v = vector<ll>(n, 0);
        this->size = size;
        ones = 0;

        prune = size - ((size - 1) % 64) - 1;
        this->mask = ~1;
        this->mask = (this->mask >> prune);
    }

    void fix(int idx)
    {
        int i = n - (idx / 64), pos = idx % 64;
        ll mask = 1 << pos;
        ll prev = v[i];
        v[i] = v[i] | mask;
        v[0] = v[0] & (this->mask);
        if (v[i] != prev)
            ones++;
    }

    void unfix(int idx)
    {
        int i = n - (idx / 64), pos = idx % 64;
        ll mask = 1 << pos;
        pos = ~pos;
        ll prev = v[i];
        v[i] = v[i] & mask;
        v[0] = v[0] & (this->mask);
        if (v[i] != prev)
            ones--;
    }

    void flip()
    {
        for (int i = 0; i < n; i++)
        {
            v[i] = ~v[i];
        }
        v[0] = v[0] & (this->mask);
        ones = size - ones;
    }

    bool all()
    {
        return this->count() == size;
    }

    bool one()
    {
        return ones > 0;
    }

    int count()
    {
        return ones;
    }

    string toString()
    {
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */