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

    int N = 200000;
    vector<vector<int>> pref(31, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < 31; j++)
        {
            pref[j][i] += pref[j][i - 1];
            if (i & (1 << j))
                pref[j][i]++;
        }
    }

    while (t--)
    {
        int l, r;
        cin >> l >> r;

        int ans = 0;
        for (int i = 0; i < 31; i++)
        {
            ans = max(ans, pref[i][r] - pref[i][l - 1]);
        }
        cout << (r - l + 1 - ans) << endl;
    }
    return 0;
}