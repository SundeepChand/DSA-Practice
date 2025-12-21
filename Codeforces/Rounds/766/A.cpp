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
        int n, m, r, c;
        cin >> n >> m >> r >> c;

        r--, c--;

        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        if (v[r][c] == 'B')
        {
            cout << 0 << endl;
            continue;
        }

        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (v[i][c] == 'B')
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            cout << 1 << endl;
            continue;
        }
        for (int i = 0; i < m; i++)
        {
            if (v[r][i] == 'B')
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            cout << 1 << endl;
            continue;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (v[i][j] == 'B')
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }
        if (flag)
        {
            cout << 2 << endl;
            continue;
        }
        cout << -1 << endl;
    }
    return 0;
}