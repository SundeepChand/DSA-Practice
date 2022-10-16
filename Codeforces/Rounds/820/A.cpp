#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int32_t main()
{
    /*
    Related to abs sum

    */
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        int ta = abs(1 - a), tb = abs(b - c) + abs(1 - c);
        if (ta == tb)
            cout << 3;
        else if (ta < tb)
            cout << 1;
        else
            cout << 2;
        cout << endl;
    }
    return 0;
}