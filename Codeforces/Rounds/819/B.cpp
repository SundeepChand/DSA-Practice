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

    /*

    m % n == 0 => a[i] = m / n;

    */

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> ans(n, m / n);
        bool flag = false;
        if ((m / n) != 0)
        {
            if (m % n == 0)
            {
                flag = true;
            }
            else if ((n - (m % n)) % 2 == 0)
            {
                flag = true;
                for (int i = 0; i < m % n; i++)
                    ans[i]++;
            }
            else if (n % 2 == 1)
            {
                flag = true;
                ans = vector<int>(n, 1);
                ans[0] = m - (n - 1);
            }
        }

        if (!flag)
            cout << "No";
        else
        {
            cout << "Yes" << endl;
            for (int x : ans)
                cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}