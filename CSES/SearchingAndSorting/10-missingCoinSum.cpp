#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;

    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    ll curSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > curSum + 1)
            break;
        curSum += v[i];
    }
    cout << (curSum + 1) << endl;

    return 0;
}