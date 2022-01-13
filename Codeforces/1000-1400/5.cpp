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

        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i].first;
            v[i].second = i;
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());

        int tot = 0, cur = 1;
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            tot += (2 * v[i].first * abs(cur));
            ans[v[i].second] = cur;
            if (cur > 0)
                cur = -cur;
            else
                cur = (-cur) + 1;
        }

        cout << tot << endl;
        cout << 0 << " ";
        for (int x : ans)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}