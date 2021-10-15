#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ll n, x;
    cin >> n >> x;

    ll ans = 0;
    map<ll, int> u;
    ll pref;
    cin >> pref;
    if (pref == x)
        ans++;
    u[pref] = 1;
    for (int i = 1; i < n; i++)
    {
        ll cur;
        cin >> cur;
        pref += cur;
        if (pref == x)
            ans++;
        ans += u[pref - x];
        u[pref]++;
    }
    cout << ans << endl;
    return 0;
}