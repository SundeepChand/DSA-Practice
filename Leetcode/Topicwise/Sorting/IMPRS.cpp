#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

bool cmp(vector<int> &a, vector<int> &b)
{
    int dist_a = a[0] * a[0] + a[1] * a[1];
    int dist_b = b[0] * b[0] + b[1] * b[1];
    if (dist_a == dist_b)
        return (a[0] + a[1]) < (b[0] + b[1]);
    return dist_a < dist_b;
}

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

        vector<vector<int>> v(n, vector<int>(2));
        for (int i = 0; i < n; i++)
        {
            cin >> v[i][0] >> v[i][1];
        }

        sort(v.begin(), v.end(), cmp);
        int ans = 0;
        for (int i = 0; i < k; i++)
        {
            ans += (v[i][0] + v[i][1]);
        }
        cout << ans << endl;
    }
    return 0;
}