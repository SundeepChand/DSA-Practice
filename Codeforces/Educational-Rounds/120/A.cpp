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

        vector<int> v = {a, b, c};
        sort(v.begin(), v.end());
        if (v[2] == v[0] + v[1])
            cout << "YES" << endl;
        else if ((a == b && c % 2 == 0) || (a == c && b % 2 == 0) || (c == b && a % 2 == 0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}