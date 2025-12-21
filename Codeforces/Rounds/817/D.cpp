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

        string s;
        cin >> s;

        /*

            LLLRRR

            RRR LLL

        */

        int tot = 0;
        vector<int> diff(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'L')
                tot += i, diff[i] = n - 1 - i - i;
            else
                tot += (n - 1 - i), diff[i] = i - n + 1 + i;
        }
        sort(diff.begin(), diff.end(), greater<int>());

        vector<int> ans(n, tot);
        for (int i = 0; i < n; i++)
        {
            if (diff[i] > 0)
                tot += diff[i];
            ans[i] = tot;
        }

        for (int x : ans)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}