#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
Make a table, mark the positions reducible to 0. And find a pattern between them.
*/

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll a, b;
        cin >> a >> b;

        if ((a + b) % 3 == 0 && (abs(a - b) <= ((a + b) / 3)))
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}