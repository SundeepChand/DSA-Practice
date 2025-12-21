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

        int ans = 0, val = v[0];
        for (int i = 1; i < n; i++)
        {
            int diff = v[i] - v[i - 1];
            if (diff > 0)
            {
                ans += diff;
            }
            else if (diff < 0)
            {
                ans -= diff;
                val += diff;
            }
        }

        cout << (ans + abs(val))<<endl;
    }
    return 0;
}