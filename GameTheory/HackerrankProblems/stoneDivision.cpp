// https://www.hackerrank.com/challenges/stone-division/problem
#include <bits/stdc++.h>
using namespace std;

// This solution is straightforward, where we calculate the grundy values and return the answer.
typedef long long ll;
typedef unsigned long long ull;

unordered_map<int, int> dp;
ll mex(const unordered_set<ll> &u)
{
    for (ll i = 0; true; i++)
        if (u.find(i) == u.end())
            return i;
    return -1;
}
ll grundy(ll n, int m, const vector<ll> &v)
{
    if (dp.find(n) != dp.end())
        return dp[n];

    unordered_set<ll> u;
    for (ll i = 0; i < m; i++)
    {
        if (n % v[i] == 0)
        {
            if (v[i] % 2 == 1)
                u.insert(grundy(n / v[i], m, v));
            else
                u.insert(0);
        }
    }

    return dp[n] = mex(u);
}

int main()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> v(m);
    for (ll i = 0; i < m; i++)
    {
        cin >> v[i];
    }

    if (grundy(n, m, v))
    {
        cout << "First";
    }
    else
    {
        cout << "Second";
    }
    cout << endl;
    return 0;
}