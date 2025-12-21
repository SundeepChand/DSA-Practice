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
        int n, c;
        cin >> n >> c;

        int ans = 0;
        vector<int> orb(100, 0);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            orb[x - 1]++;
        }

        for (int x : orb)
        {
            if (x > c)
                ans += c;
            else
                ans += x;
        }
        cout << ans << endl;
    }
    return 0;
}