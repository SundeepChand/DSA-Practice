// https://codeforces.com/problemset/problem/312/B
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int long double

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int den = b * (a / b + c / d - ((a * c) / (b * d)));
    int ans = a / den;
    cout.setf(ios::fixed);
    cout << setprecision(15) << ans << endl;
    return 0;
}