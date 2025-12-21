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
        int n;
        cin >> n;

        if (n % 3 == 0)
        {
            cout << (n / 3);
        }
        else if (n % 3 == 1)
        {
            cout << min(1 + ((n + 2) / 3), 2 + abs((n - 4) / 3));
        }
        else
        {
            cout << (1 + ((n - 2) / 3));
        }
        cout << endl;
    }
    return 0;
}