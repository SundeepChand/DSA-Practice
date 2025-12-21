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

        vector<vector<int>> dp(n, vector<int>(2, 0));
        for (int i = 0; i < n; i++)
        {
            int color = v[i] - 1;
            bool parity = i % 2;
            dp[color][parity] = max(dp[color][parity], 1 + dp[color][!parity]);
        }

        for (int i = 0; i < n; i++)
            cout << max(dp[i][0], dp[i][1]) << " ";
        cout << endl;
    }
    return 0;
}