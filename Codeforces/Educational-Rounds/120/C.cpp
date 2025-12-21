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
        int n, k;
        cin >> n >> k;

        vector<int> v(n);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            sum += v[i];
        }
        if (sum <= k)
        {
            cout << 0 << endl;
            continue;
        }
        sort(v.begin(), v.end());

        int ans = (sum - k);
        int cur = 0;
        for (int i = n - 1; i > 0; i--)
        {
            cur += v[i];
            int x = ceil(double(k + cur - sum - (n - i) * v[0]) / double(n - i + 1));
            int temp = x + (n - i);
            if (temp < 0)
                temp = 0;
            ans = min(ans, temp);
        }

        cout << ans << endl;
    }
    return 0;
}