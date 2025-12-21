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

        // vector<int> x, y;
        int ans = 0;
        int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;

            if (a == 0)
            {
                if (b > 0)
                    y1 = max(y1, b);
                else if (b < 0)
                    y2 = min(y2, b);
            }
            else if (b == 0)
            {
                if (a > 0)
                    x1 = max(x1, a);
                else if (a < 0)
                    x2 = min(x2, a);
            }
        }

        ans = 2 * abs(x1) + 2 * abs(x2) + 2 * abs(y1) + 2 * abs(y2);
        cout << ans << endl;
    }
    return 0;
}