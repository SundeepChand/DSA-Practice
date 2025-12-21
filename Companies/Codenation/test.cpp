#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;
#define int ull

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

int diffMod(int a, int b, int m)
{
    return ((a % m - b % m) % m + m) % m;
}

int multMod(int a, int b, int m)
{
    return (a % m * b % m) % m;
}

int paths(int A, int B)
{
    factorialMod();

    int ans = nCr(2 * A - 2, A - 1);

    for (int i = A / 2 - B; i <= A / 2 + B; i++)
    {
        int h_up = A / 2 - B + 1, w_left = i + 1;
        int h_down = A - h_up + 1, w_right = A - w_left + 1;
        ans = diffMod(ans, multMod(nCr(h_up + w_left - 2, w_left - 1), nCr(h_down + w_right - 2, w_right - 1), MOD), MOD);
    }
    for (int i = A / 2 - B + 1; i <= A / 2 + B; i++)
    {
        int h_up = i + 1, w_left = A / 2 - B + 1;
        int h_down = A - h_up + 1, w_right = A - w_left + 1;
        ans = diffMod(ans, multMod(nCr(h_up + w_left - 2, w_left - 1), nCr(h_down + w_right - 2, w_right - 1), MOD), MOD);
    }
    return ans;
}

int32_t main()
{
    cout<<paths(3, 0)<<endl;
    cout<<paths(5, 0)<<endl;
    return 0;
}
