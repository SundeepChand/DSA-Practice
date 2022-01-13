#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

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

int fact(int n)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
        ans = (ans * i) % MOD;
    return ans;
}

int solve(int n)
{
    int ans = (fact(2 * n) * modInverse(fact(n), MOD)) % MOD;
    ans = (ans * modInverse(fact(n + 1), MOD)) % MOD;
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    if (n % 2 == 1)
        cout << 0 << endl;
    else
        cout << solve(n / 2) << endl;
    return 0;
}