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
        int w, h;
        cin >> w >> h;

        int ans = 0;

        int a1 = w, b1 = 0, k1;
        cin >> k1;
        for (int i = 0; i < k1; i++)
        {
            int x;
            cin >> x;
            a1 = min(a1, x);
            b1 = max(b1, x);
        }
        ans = max(ans, h * (b1 - a1));

        cin >> k1;
        a1 = w, b1 = 0;
        for (int i = 0; i < k1; i++)
        {
            int x;
            cin >> x;
            a1 = min(a1, x);
            b1 = max(b1, x);
        }
        ans = max(ans, h * (b1 - a1));

        a1 = h, b1 = 0;
        cin >> k1;
        for (int i = 0; i < k1; i++)
        {
            int x;
            cin >> x;
            a1 = min(a1, x);
            b1 = max(b1, x);
        }
        ans = max(ans, w * (b1 - a1));

        a1 = h, b1 = 0;
        cin >> k1;
        for (int i = 0; i < k1; i++)
        {
            int x;
            cin >> x;
            a1 = min(a1, x);
            b1 = max(b1, x);
        }
        ans = max(ans, w * (b1 - a1));

        cout << ans << endl;
    }
    return 0;
}