#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;

int fast_multiply(ll a, ll b, int c)
{
    int ans = 0;
    while (b)
    {
        if (b & 1)
        {
            ans += a;
            ans %= c;
        }
        a += a;
        a %= c;
        b >>= 1;
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ll a, b;
    cin >> a >> b;

    cout << fast_multiply(a, b, MOD) << endl;
    return 0;
}