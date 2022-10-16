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

        int ans = 0;
        int cur = 1;
        while (k)
        {
            if (k & 1)
            {
                ans = (ans + cur) % MOD;
            }
            k >>= 1;
            cur = (cur * n) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}