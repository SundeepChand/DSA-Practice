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
        int n, k;
        cin >> n >> k;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        vector<vector<int>> v(n, vector<int>(2));
        for (int i = 0; i < n; i++)
        {
            v[i][0] = a[i], v[i][1] = b[i];
        }

        sort(v.begin(), v.end());

        int i = 0;
        for (; i < n && v[i][0] <= k; i++)
        {
            k += v[i][1];
        }
        cout << k << endl;
    }
    return 0;
}