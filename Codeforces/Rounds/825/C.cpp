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

        int ans = 0;
        int i = 0, j = 0;

        while (i < n)
        {
            while (j < n and v[j] >= (j - i + 1))
            {
                j++;
                ans += (j - i);
            }

            // int len = j - i;
            // ans += (len * (len + 1)) / 2;

            i++;
        }
        cout << ans << endl;
    }
    return 0;
}