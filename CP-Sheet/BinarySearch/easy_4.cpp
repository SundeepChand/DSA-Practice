#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

bool canSolve(vector<int> &v, int k, int h)
{
    int tot = 0;
    for (int i = 0; i < v.size() - 1; i++)
    {
        tot += min(k, v[i + 1] - v[i]);
    }
    tot += k;
    return tot >= h;
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
        int n, h;
        cin >> n >> h;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        int lb = 1, ub = 1e18;
        int ans = ub;
        while (lb <= ub)
        {
            int mid = lb + (ub - lb) / 2;
            if (canSolve(v, mid, h))
            {
                ub = mid - 1;
                ans = mid;
            }
            else
                lb = mid + 1;
        }
        cout << ans << endl;
    }
    return 0;
}