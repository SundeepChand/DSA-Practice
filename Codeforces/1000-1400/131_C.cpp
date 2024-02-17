#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

bool canSolve(int n, int m, map<int, int> &mp, int t)
{
    int W = 0;
    for (int i = 1; i <= n; i++)
    {
        W += ((t - min(t, mp[i])) / 2) + min(t, mp[i]);
    }
    return W >= m;
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
        int n, m;
        cin >> n >> m;

        vector<int> v(m);
        map<int, int> mp;
        for (int i = 0; i < m; i++)
        {
            cin >> v[i];
            mp[v[i]]++;
        }

        int lb = 0, ub = 2 * m;
        int ans = ub;
        while (lb <= ub)
        {
            int mid = lb + (ub - lb) / 2;

            if (canSolve(n, m, mp, mid))
            {
                ans = mid;
                ub = mid - 1;
            }
            else
                lb = mid + 1;
        }
        cout << ans << endl;
    }
    return 0;
}