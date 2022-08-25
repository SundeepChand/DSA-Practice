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

    /*
    c*d -> Lime slices
    k*l -> drink
    p   -> salt

    max. toast (m) = min(k*l / n1, c*d, p / np)

    ans = (m / n) * n

    */
    int n, k, l, c, d, p, n1, np;
    cin >> n >> k >> l >> c >> d >> p >> n1 >> np;

    int m = min({(k * l) / n1, c * d, p / np});
    cout << (m / n) << endl;

    return 0;
}