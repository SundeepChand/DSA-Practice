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

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
        cin >> b[i];

    int g = 0;
    for (int i = 1; i < n; i++)
    {
        g = __gcd(g, abs(a[i] - a[i - 1]));
    }

    for (int i = 0; i < m; i++)
    {
        cout << __gcd(g, a[0] + b[i]) << " ";
    }
    cout << endl;
    return 0;
}