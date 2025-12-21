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

    XOR of all elements should be 0.

    1 ^ 2 ^ 3 ^ 4 = 4

    000001
    000010
    000011
    100100

    */

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        int xr = 0;
        for (int i = 0; i < n - 2; i++)
        {
            v[i] = i;
            xr = xr ^ i;
        }

        if (xr == 0)
        {
            xr = 0;
            for (int i = 0; i < n - 2; i++)
            {
                v[i] = i + 1;
                xr = xr ^ (i + 1);
            }
        }

        v[n - 2] = 1 << 30;
        xr = xr ^ v[n - 2];
        v[n - 1] = xr;

        for (int x : v)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}