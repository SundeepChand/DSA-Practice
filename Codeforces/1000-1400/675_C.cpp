// https://codeforces.com/contest/1422/problem/C
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

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

int divide(ll a, ll b)
{
    // Return (a / b) % MOD
    return ((a % MOD) * modInverse(b, MOD)) % MOD;
}

int add(int a, int b)
{
    return ((ll)a + b) % MOD;
}

int mult(int a, int b)
{
    return (((ll)a) * b) % MOD;
}

int pow10mod(int n)
{
    int cur = 10, ans = 1;
    while (n)
    {
        if (n & 1)
            ans = (ans * cur) % MOD;
        n >>= 1;
        cur = (cur * cur) % MOD;
    }
    return ans;
}

int getGP(int n)
{
    int nr = (pow10mod(n) - 1) % MOD;
    int dr = 9;
    return divide(nr, dr);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    string s;
    cin >> s;

    int n = s.size();

    int ans = 0, cur = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        ans = add(ans, mult(cur, i + 1));
        cur = add(cur, mult(s[i] - '0', pow10mod(n - 1 - i)));
    }
    cur = 0;
    for (int i = 0; i < n; i++)
    {
        ans = add(ans, mult(cur, getGP(n - i)));
        cur = add(mult(10, cur), s[i] - '0');
    }
    cout << ans << endl;
    return 0;
}