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

        vector<int> v1, v2;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            if (i % 2 == 0)
            {
                v1.push_back(x);
            }
            else
            {
                v2.push_back(x);
            }
        }

        int gcd1 = v1[0], gcd2 = v2[0];
        for (int i = 1; i < v1.size(); i++)
        {
            gcd1 = __gcd(gcd1, v1[i]);
        }
        for (int i = 1; i < v2.size(); i++)
        {
            gcd2 = __gcd(gcd2, v2[i]);
        }

        bool f1 = true;
        for (int i = 0; i < v2.size(); i++)
        {
            if (v2[i] % gcd1 == 0)
            {
                f1 = false;
                break;
            }
        }
        if (f1)
        {
            cout << gcd1 << endl;
            continue;
        }
        f1 = true;
        for (int i = 0; i < v1.size(); i++)
        {
            if (v1[i] % gcd2 == 0)
            {
                f1 = false;
                break;
            }
        }
        if (f1)
        {
            cout << gcd2 << endl;
            continue;
        }
        cout << 0 << endl;
    }
    return 0;
}