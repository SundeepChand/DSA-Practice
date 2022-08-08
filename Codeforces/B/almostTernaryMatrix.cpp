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
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i % 4 == 0 or i % 4 == 3)
                {
                    if (j % 4 == 0 or j % 4 == 3)
                        cout << 0;
                    else
                        cout << 1;
                }
                else
                {
                    if (j % 4 == 1 or j % 4 == 2)
                        cout << 0;
                    else
                        cout << 1;
                }
                cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}