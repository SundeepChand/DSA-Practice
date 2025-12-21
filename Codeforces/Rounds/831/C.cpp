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

        sort(v.begin(), v.end());

        int ans = 0;
        for (int i = 0; i < n - 2; i++)
        {
            ans = max(ans, (v[n - 1] - v[i]) + (v[i + 1] - v[i]));
        }
        for (int i = n - 1; i > 1; i--)
        {
            ans = max(ans, (v[i] - v[0]) + (v[i] - v[i - 1]));
        }
        cout << ans << endl;
    }
    return 0;
}