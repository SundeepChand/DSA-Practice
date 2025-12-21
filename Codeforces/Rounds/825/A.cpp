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

        vector<int> a(n), b(n);
        int ct1 = 0, ct2 = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i])
                ct1++;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            if (b[i])
                ct2++;
        }

        int swaps = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                swaps++;
            }
        }

        cout << min(1 + abs(ct1 - ct2), swaps) << endl;
    }
    return 0;
}