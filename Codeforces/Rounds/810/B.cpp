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
        int n, m;
        cin >> n >> m;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        vector<vector<int>> pairs(m, vector<int>(2));
        vector<int> f(n, 0);
        for (int i = 0; i < m; i++)
        {
            cin >> pairs[i][0] >> pairs[i][1];
            pairs[i][0]--, pairs[i][1]--;
            f[pairs[i][0]]++, f[pairs[i][1]]++;
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (f[i] % 2 == 1)
                ans = min(ans, v[i]);
        }

        for (int i = 0; i < m; i++)
        {
            if (f[pairs[i][0]] % 2 == 0 and f[pairs[i][1]] % 2 == 0)
                ans = min(ans, v[pairs[i][0]] + v[pairs[i][1]]);
        }

        if (m % 2 == 0)
            cout << 0;
        else
            cout << ans;
        cout << endl;
    }
    return 0;
}