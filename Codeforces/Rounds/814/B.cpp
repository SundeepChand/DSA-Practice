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

        vector<int> v(n);

        if (k % 2 == 1)
        {
            cout << "YES" << endl;
            for (int i = 1; i <= n; i += 2)
            {
                cout << i << " " << i + 1 << endl;
            }
        }
        else if (k % 4 == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            for (int i = 1, j = 0; i <= n; i += 2, j = !j)
            {
                if (j)
                {
                    cout << i << " " << (i + 1);
                }
                else
                    cout << (i + 1) << " " << i;
                cout << endl;
            }
        }
    }
    return 0;
}