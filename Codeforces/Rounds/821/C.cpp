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

    /*

    1 10000 3 0 5

    */

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

        vector<pair<int, int>> ans;
        if (v[0] != v[n - 1])
        {
            if ((v[0] + v[n - 1]) % 2 == 0)
                v[0] = v[n - 1];
            else
                v[n - 1] = v[0];
            ans.push_back({0, n - 1});
        }

        for (int i = 1; i < n - 1; i++)
        {
            if (v[i] == v[0])
                continue;
            if ((v[i] + v[0]) % 2 == 1)
            {
                v[i] = v[0];
                ans.push_back({0, i});
            }
            else
            {
                v[i] = v[0];
                ans.push_back({i, n - 1});
            }
        }

        cout << ans.size() << endl;
        for (auto x : ans)
            cout << (x.first + 1) << " " << (x.second + 1) << endl;
    }
    return 0;
}