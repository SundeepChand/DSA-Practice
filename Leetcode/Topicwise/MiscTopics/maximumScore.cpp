#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
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

        vector<vector<int>> v(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> v[i][j];
            }
            sort(v[i].begin(), v[i].end());
        }

        int ans = 0;
        int i = n - 1, prev = INT_MAX;
        bool flag = false;
        while (i >= 0)
        {
            int j = lower_bound(v[i].begin(), v[i].end(), prev) - v[i].begin();
            j--;
            if (j == -1)
            {
                flag = true;
                break;
            }
            ans += v[i][j];
            prev = v[i][j];
            i--;
        }

        if (flag)
            cout << -1;
        else
            cout << ans;
        cout << endl;
    }
    return 0;
}