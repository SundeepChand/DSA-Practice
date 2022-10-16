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
        int n, x, y;
        cin >> n >> x >> y;

        /*
        TC1:
        5 8 7
        01001
        00101

        100
        010

        */

        string a, b;
        cin >> a >> b;
        vector<int> c(n);
        int ctr = 0;
        vector<int> pos;
        for (int i = 0; i < n; i++)
        {
            c[i] = (a[i] - '0') ^ (b[i] - '0');
            cerr << c[i];
            if (c[i])
            {
                ctr++;
                pos.push_back(i);
            }
        }

        if (ctr % 2 == 1)
            cout << -1;
        else
        {
            if (ctr == 2)
            {
                if (pos[1] - pos[0] == 1)
                    cout << min(x, 2 * y);
                else
                    cout << y;
            }
            else
            {
                cout << (ctr / 2) * y;
            }
        }
        cout << endl;
    }
    return 0;
}