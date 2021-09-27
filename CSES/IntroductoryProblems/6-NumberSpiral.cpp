#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll x, y;
        cin >> y >> x;

        if (x >= y)
        {
            if (x % 2 == 1)
            {
                cout << (x * x - y + 1);
            }
            else
            {
                cout << (x * x - 2 * x + y + 1);
            }
        }
        else
        {
            if (y % 2 == 0)
            {
                cout << (y * y - x + 1);
            }
            else
            {
                cout << (y * y - 2 * y + x + 1);
            }
        }
        cout << endl;
    }
    return 0;
}