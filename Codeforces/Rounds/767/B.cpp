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
        int l, r, k;
        cin >> l >> r >> k;

        if (l == r)
        {
            if (l == 1)
                cout << "NO";
            else
                cout << "YES";
            cout << endl;
            continue;
        }

        int odd;
        if (l % 2 == 1)
            odd = ceil((r - l + 1) / double(2.0));
        else
            odd = (r - l + 1) / 2;

        int even = (r - l + 1) - odd;
        if (odd == 0)
            cout << "YES";
        else
        {
            if (odd > k)
                cout << "NO";
            else
                cout << "YES";
        }
        cout << endl;
    }
    return 0;
}