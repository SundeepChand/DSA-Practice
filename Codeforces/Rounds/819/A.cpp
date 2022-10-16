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

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        int minVal = v[0], maxVal = v[0];
        for (int i = 0; i < n - 1; i++)
        {
            minVal = min(minVal, v[i]);
        }
        for (int i = 1; i < n; i++)
        {
            maxVal = max(maxVal, v[i]);
        }

        int maxDiff = max({v[n - 1] - v[0], maxVal - v[0], v[n - 1] - minVal});
        for (int i = 1; i < n; i++)
        {
            maxDiff = max(maxDiff, v[i - 1] - v[i]);
        }
        cout << maxDiff << endl;
    }
    return 0;
}