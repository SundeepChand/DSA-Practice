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

        string s;
        cin >> s;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            // if (i == 0)
            // {
            //     if (s[i] == '1')
            //     ans += v[0];
            //     continue;
            // }

            if (s[i] == '1')
            {
                // Check if moving it is beneficial
                int j = i, cur = 0, curMin = v[i];
                if (i > 0)
                    cur = v[i - 1], curMin = min(curMin, v[i - 1]);

                while (j < n and s[j] == '1')
                {
                    cur += v[j], curMin = min(curMin, v[j]);
                    j++;
                }
                if (i == 0)
                    curMin = 0;
                ans += (cur - curMin);
                i = j;
            }
        }
        cout << ans << endl;
    }
    return 0;
}