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
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> v(k);
        for (int i = 0; i < k; i++)
        {
            cin >> v[i];
        }

        int coloredRows = 0;
        bool flag = (n % 2 == 0);
        for (int i = 0; i < k; i++)
        {
            int curRows = v[i] / m;
            if (curRows > 1)
            {
                coloredRows += curRows;
                if (curRows > 2)
                    flag = true;
            }
        }
        if (coloredRows >= n and flag)
        {
            cout << "Yes" << endl;
            continue;
        }

        int coloredColumns = 0;
        flag = (m % 2 == 0);
        for (int i = 0; i < k; i++)
        {
            int curColumns = v[i] / n;
            if (curColumns > 1)
            {
                coloredColumns += curColumns;
                if (curColumns > 2)
                    flag = true;
            }
        }
        if (coloredColumns >= m and flag)
        {
            cout << "Yes" << endl;
            continue;
        }
        cout << "No" << endl;
    }
    return 0;
}