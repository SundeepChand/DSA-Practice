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
        int n, x;
        cin >> n >> x;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        int ans = -1, i = 0;
        while (i < n)
        {
            ans++;
            int maxVal = v[i], minVal = v[i];
            while (i < n and maxVal - minVal <= 2 * x)
            {
                maxVal = max(maxVal, v[i]), minVal = min(minVal, v[i]);
                i++;
            }
            if (maxVal - minVal > 2 * x)
                i--;
        }
        cout << ans << endl;
    }
    return 0;
}