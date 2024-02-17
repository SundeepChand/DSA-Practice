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
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> v(n);
        bool odd = x % 2;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            odd = odd ^ (v[i] % 2);
        }

        if (odd == y % 2)
            cout << "Alice";
        else
            cout << "Bob";
        cout << endl;
    }
    return 0;
}