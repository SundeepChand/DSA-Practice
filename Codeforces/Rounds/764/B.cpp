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

        int n1 = 2 * b - c, n2 = (c + a), n3 = (2 * b - a);
        if (n1 % a == 0 && (n1 / a) >= 1)
            cout << "YES";
        else if (n2 % (2 * b) == 0 && (n2 / (2 * b)) >= 1)
            cout << "YES";
        else if (n3 % c == 0 && (n3 / c) >= 1)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}