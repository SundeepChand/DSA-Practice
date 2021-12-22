#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

bool canSolve(vector<vector<int>> &v, int k)
{
    int m = v.size(), n = v[0].size();
    set<int> shops;
    bool flag = false, flag1 = false;
    for (int i = 0; i < n; i++)
    {
        flag = false;
        for (int j = 0; j < m; j++)
        {
            if (v[j][i] >= k)
            {
                flag = true;
                if (shops.find(j) != shops.end())
                    flag1 = true;
                shops.insert(j);
            }
        }
        if (!flag)
            break;
    }
    return flag && flag1;
}

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
        int m, n;
        cin >> m >> n;

        vector<vector<int>> v(m, vector<int>(n));
        int lb = 1, ub = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> v[i][j];
                ub = max(ub, v[i][j]);
            }
        }

        ll ans = ub;
        while (lb <= ub)
        {
            ll mid = (lb + ub) / 2;
            if (canSolve(v, mid))
            {
                ans = mid;
                lb = mid + 1;
            }
            else
            {
                ub = mid - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}