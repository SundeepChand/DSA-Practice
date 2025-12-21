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

    vector<ll> v(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;

        v[i] = a;
        sum += b;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        sum -= (n - i) * v[i];
    }
    cout << sum << endl;
    return 0;
}