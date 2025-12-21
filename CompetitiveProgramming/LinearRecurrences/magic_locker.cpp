#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;

ll power(ll a, ll b)
{
    ll ans = 1, cur = a;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * cur) % MOD;
        }
        b >>= 1;
        cur = cur * cur;
        cur = cur % MOD;
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        ll ans = 1;
        if (n % 3 == 2)
        {
            ans *= 2;
            n -= 2;
        }
        else if (n % 3 == 1)
        {
            if (n > 3)
            {
                n -= 4;
                ans *= 4;
            }
            else
            {
                n -= 1;
            }
        }
        n /= 3;
        ll mult = power(3, n);
        ans = (ans * mult) % MOD;
        cout << ans << endl;
    }
    return 0;
}