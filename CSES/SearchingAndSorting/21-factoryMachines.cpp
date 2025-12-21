#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool canSolve(vector<ll> &v, ll k, ll ans)
{
    int i = 0;
    while (i < v.size() && k > 0)
    {
        ll x = ans / v[i];
        k -= x;
        i++;
    }
    if (k > 0)
        return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ll n, t;
    cin >> n >> t;

    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    ll lo = 1, hi = 1000000000000000000;
    ll ans = lo;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if (canSolve(v, t, mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    cout << ans << endl;
    return 0;
}