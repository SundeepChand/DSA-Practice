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

        vector<vector<int>> v(n, vector<int>(2));
        int maxW = -1, maxH = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i][0] >> v[i][1];
            maxW = max(maxW, v[i][0]), maxH = max(maxH, v[i][1]);
        }

        int ans1 = maxW, ans2 = maxH;
        for (int i = 0; i < n; i++)
        {
            int w = v[i][0], h = v[i][1];

            if (h < w or h > maxW)
                ans1 += h;
            else
                ans1 += w;

            if (w <= maxH and h < w)
                ans2 += h;
            else
                ans2 += w;
        }
        // cerr << H << " " << s << endl;
        cout << 2 * min(ans1, ans2) << endl;
    }
    return 0;
}