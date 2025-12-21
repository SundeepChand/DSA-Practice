#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

/*
    cur = cur state the player is in
    0 = air
    1 = water
    2 = fire
*/
ull dp[1001][1001][3];
ull maxTime(int h, int a, int cur)
{
    if (h <= 0 or a <= 0)
        return 0;
    if (dp[h][a][cur] != -1)
        return dp[h][a][cur];

    ull ans = 0;
    if (cur == 0)
        ans = max({ans,
                   1 + maxTime(h - 5, a - 10, 1),
                   1 + maxTime(h - 20, a + 5, 2)});

    else if (cur == 1)
        ans = max({ans,
                   1 + maxTime(h + 3, a + 2, 0),
                   1 + maxTime(h - 20, a + 5, 2)});

    else
        ans = max({ans,
                   1 + maxTime(h + 3, a + 2, 0),
                   1 + maxTime(h - 5, a - 10, 1)});

    return dp[h][a][cur] = ans;
}

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
        int h, a;
        cin >> h >> a;
        memset(dp, -1, sizeof(dp));
        cout << maxTime(h + 3, a + 2, 0) << endl;
    }
    return 0;
}