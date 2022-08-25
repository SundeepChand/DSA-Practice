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
        int n, q;
        cin >> n >> q;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        int curQ = 0;
        string s(n, '0');
        for (int i = n - 1; i >= 0; i--)
        {
            if (curQ >= v[i])
                s[i] = '1';
            else if (curQ < q)
                s[i] = '1', curQ++;
        }
        cout << s << endl;
    }
    return 0;
}