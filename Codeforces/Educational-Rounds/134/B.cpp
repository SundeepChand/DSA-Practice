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
        int n, m, x, y, d;
        cin >> n >> m >> x >> y >> d;

        int up = x - d, down = x + d, left = y - d, right = y + d;
        if (up <= 1)
        {
            if (left <= 1)
                cout << -1;
            else if (down >= n)
                cout << -1;
            else
                cout << (m + n - 2);
        }
        else if (right >= m)
        {
            if (left <= 1)
                cout << -1;
            else if (down >= n)
                cout << -1;
            else
                cout << (m + n - 2);
        }
        else
            cout << (m + n - 2);
        cout << endl;
    }
    return 0;
}