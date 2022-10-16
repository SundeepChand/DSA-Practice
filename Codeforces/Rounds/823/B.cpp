#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

double canReach(vector<pair<int, int>> &v, double t)
{
    int n = v.size();

    double r = INT_MAX, l = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (v[i].second > t)
            return LONG_LONG_MIN;
        r = min(r, v[i].first + t - v[i].second);
        l = max(l, v[i].first - t + v[i].second);
    }
    if (l <= r)
        return (l + r) / 2.0;
    return LONG_LONG_MIN;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    cout.setf(ios::fixed);
    cerr.setf(ios::fixed);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i].first;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> v[i].second;
        }

        sort(v.begin(), v.end());

        double lb = 0, ub = 1e18, ans = -1;
        while (ub - lb >= 1e-7)
        {
            double mid = lb + (ub - lb) / 2.0;
            double curAns = canReach(v, mid);

            // cerr << lb << " " << mid << " " << ub << " " << curAns << endl;
            if (curAns == LONG_LONG_MIN)
            {
                lb = mid;
            }
            else
            {
                ans = curAns;
                ub = mid;
            }
        }
        cout << setprecision(7) << ans << endl;
    }
    return 0;
}