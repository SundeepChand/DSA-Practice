#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

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

    while (t--)
    {
        long double n;
        cin >> n;

        int rt1 = sqrt(n);
        int rt2 = cbrt(n);
        int rt3 = sqrt(cbrt(n));
        cout << (rt1 + rt2 - rt3) << endl;
    }
    return 0;
}