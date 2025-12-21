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

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        vector<int> b(n + 1);
        b[0] = v[0], b[n] = v[n - 1];

        for (int i = 1; i < n; i++)
        {
            b[i] = (v[i - 1] * v[i]) / __gcd(v[i - 1], v[i]);
        }

        bool flag = true;
        for (int i = 1; i <= n; i++)
        {
            if (__gcd(b[i], b[i - 1]) != v[i - 1])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}