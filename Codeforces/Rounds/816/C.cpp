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

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    int ans = (n * (n + 1)) / 2;

    cin >> v[0];
    for (int i = 1; i < n; i++)
    {
        cin >> v[i];
        if (v[i] != v[i - 1])
        {
            ans += i * (n - i);
        }
    }
    // cerr << "Init: " << ans << endl;

    for (int i = 0; i < m; i++)
    {
        int j, x;
        cin >> j >> x;
        j--;

        // cerr << j << " " << x << endl;
        if (j > 0 and v[j - 1] != v[j])
        {
            ans -= j * (n - j);
        }
        if (j < n - 1 and v[j + 1] != v[j])
        {
            ans -= (j + 1) * (n - j - 1);
        }
        v[j] = x;
        if (j > 0 and v[j - 1] != v[j])
        {
            ans += j * (n - j);
        }
        if (j < n - 1 and v[j + 1] != v[j])
        {
            ans += (j + 1) * (n - j - 1);
        }

        cout << ans << endl;
    }
    return 0;
}