#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    double phi = (1 + sqrt(5.0)) / 2.0;
    phi *= phi;

    while (t--)
    {
        ll n;
        cin >> n;
        n %= MOD;

        cout << (ll(floor(double(n) * phi)) % MOD) << endl;
    }
    return 0;
}