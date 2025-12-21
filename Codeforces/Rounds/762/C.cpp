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
        int a, s;
        cin >> a >> s;

        string b;
        bool flag = false;
        while (s)
        {
            int da = a % 10;
            int ds = s % 10;
            if (ds < da)
            {
                s /= 10;
                ds = (s % 10) * 10 + ds;
            }
            int db = ds - da;
            if (db < 0 || db >= 10)
            {
                flag = true;
                break;
            }
            b = to_string(db) + b;
            s /= 10;
            a /= 10;
        }
        if (flag || a)
        {
            cout << -1;
        }
        else
        {
            b.erase(0, b.find_first_not_of('0'));
            if (b == "")
                cout << 0;
            else
                cout << b;
        }
        cout << endl;
    }
    return 0;
}