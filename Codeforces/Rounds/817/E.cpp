#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

#define MAX 1001

int dp[MAX][MAX];
int mp[MAX][MAX];

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
        int n, q;
        cin >> n >> q;

        /*

        What if we maintain a grid of size 1000 x 1000

        grid[i][j] = total area of all rect. with width <= i and height <= j

        q[k] = grid[wb - 1][hb - 1] - grid[ws][hs]

        Ex:

        2 1
        2 3
        3 2

        grid = {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        }
        grid[i][j] = grid[i][j - 1] + grid[i - 1][j] - grid[i - 1][j - 1] + (area of rect. with dim. i x j) * (no. of such rect).

        so need a map from (width, height) -> count

        */

        memset(mp, 0, sizeof(mp));
        for (int i = 0; i < n; i++)
        {
            int w, h;
            cin >> h >> w;
            mp[w][h]++;
        }

        dp[0][0] = 0;
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                dp[i][j] = mp[i][j] * (i * j);
                if (i == 0 and j == 0)
                    continue;
                if (i == 0)
                {
                    dp[i][j] += dp[i][j - 1];
                }
                else if (j == 0)
                {
                    dp[i][j] += dp[i - 1][j];
                }
                else
                    dp[i][j] += dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
            }
        }

        for (int i = 0; i < q; i++)
        {
            int hs, ws, hb, wb;
            cin >> hs >> ws >> hb >> wb;

            cout << dp[wb - 1][hb - 1] - dp[ws][hb - 1] - dp[wb - 1][hs] + dp[ws][hs] << endl;
        }
    }
    return 0;
}