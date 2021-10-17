#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool canSolve(vector<ll> &v, ll k, ll sum, ll ans)
{
    ll cur = 0, n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (v[i] > ans)
            return false;
        if (cur + v[i] > ans)
        {
            cur = 0;
            i--;
            k--;
        }
        else
            cur += v[i];
    }
    if (k <= 0)
        return false;
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ll n, k;
    cin >> n >> k;

    vector<ll> v(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    ll lo = 1, hi = sum;
    ll ans = lo;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if (canSolve(v, k, sum, mid))
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