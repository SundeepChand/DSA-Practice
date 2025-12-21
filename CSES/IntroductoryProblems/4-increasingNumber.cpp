#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;

    ll sum = 0, p;
    cin >> p;
    for (int i = 1; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x < p)
        {
            sum += (p - x);
            x = p;
        }
        p = x;
    }
    cout << sum << endl;
    return 0;
}