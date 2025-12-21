#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

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

int fastExponentiation(int a, int e, int m)
{
    int ans = 1, cur = a;
    while (e)
    {
        if (e & 1)
            ans = (ans * cur) % m;
        e >>= 1, cur = (cur * cur) % m;
    }
    return ans;
}

int modInverse(int a, int m)
{
    return fastExponentiation(a, m - 2, m);
}

int nCr(int n, int r)
{
    int a = (fact[n] * modInverse(fact[n - r], MOD)) % MOD;
    return (a * modInverse(fact[r], MOD)) % MOD;
}

int dp[61][2];

int solve(int n, bool p)
{
    if (n == 2)
        return p;
    if (dp[n][p] != -1)
        return dp[n][p];

    int ans = 0;
    if (p == 1)
        ans = (nCr(n - 1, n / 2) + solve(n - 2, 0)) % MOD;
    else
        ans = (MOD + (nCr(n, n / 2) - 1 - solve(n, 1)) % MOD) % MOD;
    return dp[n][p] = ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    factorialMod();
    memset(dp, -1, sizeof(dp));

    while (t--)
    {
        int n;
        cin >> n;

        cout << solve(n, 1) << " " << solve(n, 0) << " " << 1 << endl;
    }
    return 0;
}