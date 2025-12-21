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

    ll n;
    cin >> n;

    ll ans = 0;
    map<ll, int> u;
    ll pref;
    cin >> pref;
    if (pref % n == 0)
        ans++;
    u[pref % n] = 1;
    for (int i = 1; i < n; i++)
    {
        ll cur;
        cin >> cur;
        pref += cur;
        int mod = pref % n;
        if (pref < 0)
            mod = (mod + n) % n;
        if (mod == 0)
            ans++;
        ans += u[mod];
        u[mod]++;
    }
    cout << ans << endl;
    return 0;
}