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
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = i + 1;
        }

        cout << n << endl;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int x : v)
                cout << x << " ";
            cout << endl;
            if (i > 0)
                swap(v[i], v[i - 1]);
        }
    }
    return 0;
}