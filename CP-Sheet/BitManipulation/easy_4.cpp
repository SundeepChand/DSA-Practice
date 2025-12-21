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

        vector<int> ctr(31, 0);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            for (int j = 0; j < 31; j++)
            {
                ctr[j] += ((x >> j) & 1);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            bool flag = true;
            for (int x : ctr)
            {
                if (x % i != 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}