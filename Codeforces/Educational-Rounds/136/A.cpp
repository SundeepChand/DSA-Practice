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
        int n, m;
        cin >> n >> m;

        if ((n <= 3 and m <= 3) or n == 1 or m == 1)
            cout << (n / 2 + 1) << " " << (m / 2 + 1);
        else
            cout << 1 << " " << 1;
        cout << endl;
    }
    return 0;
}