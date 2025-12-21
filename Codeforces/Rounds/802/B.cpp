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

        string s;
        cin >> s;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
            v[i] = s[i] - '0';

        if (v[0] == 9)
        {
            int i = n - 1;
            int prev = 1;
            while (i >= 0)
            {
                v[i] = prev - v[i];
                if (v[i] < 0)
                {
                    v[i] += 10;
                    prev = 0;
                }
                else
                    prev = 1;
                i--;
            }
            for (int i = 0; i < n; i++)
                cout << v[i];
        }
        else
        {
            for (int i = 0; i < n; i++)
                cout << (9 - v[i]);
        }
        cout << endl;
    }
    return 0;
}