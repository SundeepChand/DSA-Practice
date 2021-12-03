#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--)
    {
        double x1, p1, x2, p2;
        cin >> x1 >> p1 >> x2 >> p2;

        while (x1 >= 10)
        {
            p1++;
            x1 = x1 / 10.0;
        }
        while (x2 >= 10)
        {
            p2++;
            x2 = x2 / 10.0;
        }
        if (p1 < p2)
            cout << "<";
        else if (p1 > p2)
            cout << ">";
        else
        {
            if (x1 < x2)
                cout << "<";
            else if (x1 > x2)
                cout << ">";
            else
                cout << "=";
        }
        cout << endl;
    }
    return 0;
}