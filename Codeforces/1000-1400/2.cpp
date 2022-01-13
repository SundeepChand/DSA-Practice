#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;

int main()
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

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        sort(v.begin(), v.end());
        int ans = 0;
        for (int i = 0; i < (n - 2 * k); i++)
        {
            ans += v[i];
        }
        for (int i = 0; i < k; i++)
        {
            ans += floor(v[n - 2 * k + i] / double(v[n - k + i]));
        }
        cout << ans << endl;
    }
    return 0;
}