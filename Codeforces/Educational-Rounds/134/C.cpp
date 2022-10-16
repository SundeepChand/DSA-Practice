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

    /*

    Ex1:
    a:  2 3  5
    b:  7 11 13

    d1: 5  4  2
    d2: 11 10 8

    Ex2:
    a:  1 2 3 4
    b:  1 2 3 4

    d1: 0 0 0 0
    d2: 0 0 0 0

    Ex3:
    a:  10 20 30 40
    b:  22 33 33 55

    c:   4  3  2  1

    d1: 12  2  3 15
    d2:

    */

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
            cin >> b[i];

        vector<int> d1(n), d2(n);
        for (int i = 0; i < n; i++)
        {
            d1[i] = *lower_bound(b.begin(), b.end(), a[i]) - a[i];
        }

        int mx = n - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            d2[i] = b[mx] - a[i];
            if (i > 0 and b[i - 1] < a[i])
                mx = i - 1;
        }

        for (int i = 0; i < n; i++)
            cout << d1[i] << " ";
        cout << endl;
        for (int i = 0; i < n; i++)
            cout << d2[i] << " ";
        cout << endl;
    }
    return 0;
}