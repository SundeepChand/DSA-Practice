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
        int a, b, c, n;
        cin >> a >> b >> c >> n;

        int mc = max({a, b, c});
        int mrc = 3 * mc - a - b - c;
        if (mrc <= n and (n - mrc) % 3 == 0)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}