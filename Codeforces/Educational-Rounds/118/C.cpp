#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

bool canSolve(vector<ll> &a, ll k, ll h)
{
    ll tot = k;
    for (int i = 0; i < a.size() - 1; i++)
    {
        tot += min(a[i + 1] - a[i], k);
    }
    return (tot >= h);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, h;
        cin >> n >> h;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (n == 1)
        {
            cout << h << endl;
            continue;
        }
        sort(a.begin(), a.end());

        ll lb = 1, ub = h;
        ll ans = ub;
        while (lb <= ub)
        {
            ll mid = (lb + ub) / 2;
            if (canSolve(a, mid, h))
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