#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;

    int tot = 0;
    for (ll i = 5; n / i > 0; i *= 5)
    {
        tot += (n / i);
    }
    cout << tot << endl;
    return 0;
}