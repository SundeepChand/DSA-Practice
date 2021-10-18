#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ll n, a, b;
    cin >> n >> a >> b;

    vector<ll> v(n);
    cin >> v[0];
    for (int i = 1; i < n; i++)
    {
        cin >> v[i];
        v[i] += v[i - 1];
    }

    ll ans = LONG_LONG_MIN;
    multiset<ll> s;
    for (int i = 0; i < n; i++)
    {
        if (i < b && i >= a - 1)
            ans = max(v[i], ans);
        if (i >= a)
            s.insert(v[i - a]);
        if (i > b)
            s.erase(s.find(v[i - b - 1]));
        if (i >= a)
            ans = max(ans, v[i] - *s.begin());
    }
    cout << ans << endl;
    return 0;
}