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
        int n, l;
        cin >> n >> l;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        int ans = 0;
        for (int i = 0; i <= 30; i++)
        {
            int nz = 0;
            for (int j = 0; j < n; j++)
            {
                if ((v[j] & (1 << i)) == 0)
                    nz++;
            }
            if (n - nz > nz)
            {
                ans = ans | (1 << i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}