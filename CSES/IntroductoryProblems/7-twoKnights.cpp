#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;

    for (ll i = 1; i <= n; i++)
    {
        ll total = i * i * (i * i - 1) / 2;
        ll attack = 4 * (i - 1) * (i - 2);

        cout << (total - attack) << endl;
    }
    return 0;
}