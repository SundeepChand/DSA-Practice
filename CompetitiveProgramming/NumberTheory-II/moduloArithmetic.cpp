#include <bits/stdc++.h>
using namespace std;

#define MOD 5

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;

int addm(int a, int b)
{
    return (a + b) % MOD;
}

int subm(int a, int b)
{
    return ((a - b) % MOD + MOD) % MOD;
}

int multm(ll a, ll b)
{
    return (a * b) % MOD;
}

int fastExponentiation(ll a, ll e, ll m)
{
    // Use binary exponentiation to calculate (a ^ e) % m
    int ans = 1;
    ll cur = a;
    while (e)
    {
        if (e & 1)
        {
            ans = (ans * cur) % m;
        }
        e >>= 1;
        cur = (cur * cur) % m;
    }
    return ans;
}

int modInverse(ll a, ll m)
{
    // Return multiplicative modulo inverse of a by m
    return fastExponentiation(a, m - 2, m); // Using Fermat's little theorem
}

int divm(ll a, ll b)
{
    // Return (a / b) % MOD
    return ((a % MOD) * modInverse(b, MOD)) % MOD;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    cout << addm(5, 3) << endl;
    cout << subm(3, 5) << endl;
    cout << multm(3, 5) << endl;
    cout << divm(56, 2) << endl;
    return 0;
}
