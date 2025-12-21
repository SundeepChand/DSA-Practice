#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool canSolve(vector<int> &v, int k, ll x)
{
    int i = v.size() / 2;
    while (i < v.size())
    {
        if (v[i] >= x)
            return true;
        if ((x - v[i]) <= k)
        {
            k -= (x - v[i]);
        }
        else
        {
            return false;
        }
        i++;
    }
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    ll lo = 1, hi = 6000000000;
    ll ans = lo;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if (canSolve(v, k, mid))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}