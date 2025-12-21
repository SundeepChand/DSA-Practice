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

    /*
    TC 1:
    1 2 3 4 5

    2, 0

    1 2 3 4 5

    1 4 5

    4 5

    4

    1 1 4 4


    TC 2:
    1 2 3 4 5 6 7 8

    1 4 5 6 7 8

    4 5 6 7 8

    4 6 7 8

    6 7 8

    7 8

    8

    1 1 4 4 6 7 8

    1, 2

    There must be a 0
    Check if n - 1 is divisible by the remaining value
    Corner case is, (n, x, y) = (1, 0, 0)

    */

    int t;
    cin >> t;

    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;

        if ((x > 0 and y > 0) or (x == 0 and y == 0))
            cout << -1;
        else
        {
            int val = max(x, y);
            if ((n - 1) % val != 0)
                cout << -1;
            else
            {
                bool flag = 1;
                int cur = 1;
                for (int i = 0; i < n - 1;)
                {
                    for (int j = 0; j < val; j++, i++)
                    {
                        cout << cur << " ";
                    }
                    cur += val + flag;
                    if (flag)
                        flag = 0;
                }
            }
        }
        cout << endl;
    }
    return 0;
}