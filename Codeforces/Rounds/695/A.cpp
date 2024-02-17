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
        if (n == 1)
        {
            cout << 9 << endl;
            continue;
        }

        vector<int> ans(n);
        ans[0] = 8;

        int i = 1, j = n - 1;
        while (i <= j)
        {
            ans[i] = ans[j] = (8 + i) % 10;
            i++, j--;
        }

        cout << ans[n - 1];
        for (int i = 0; i < n - 1; i++)
            cout << ans[i];
        cout << endl;
    }
    return 0;
}