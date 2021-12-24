#include <bits/stdc++.h>
using namespace std;

#define MOD 7

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;

const int N = 100001;
vector<int> fact(N);
void factorialMod()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

ll fastExponentiation(ll a, ll e, ll m)
{
    ll ans = 1, cur = a;
    while (e)
    {
        if (e & 1)
            ans = (ans * cur) % m;
        e >>= 1, cur = (cur * cur) % m;
    }
    return ans;
}

ll modInverse(ll a, ll m)
{
    return fastExponentiation(a, m - 2, m);
}

int nCr(int n, int r)
{
    ll a = (fact[n] * modInverse(fact[n - r], MOD)) % MOD;
    return (a * modInverse(fact[r], MOD)) % MOD;
}

int nPr(int n, int r)
{
    return (fact[n] * modInverse(fact[n - r], MOD)) % MOD;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    factorialMod();
    cout << fact[4] << endl;
    cout << fact[5] << endl;
    cout << nCr(5, 2) << endl;
    return 0;
}