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

        string s;
        cin >> s;

        int i = n - 1;
        while (i >= 0 and s[i] != '1')
            i--;
        if (i >= 0 and s[i] == '1' and n - 1 - i <= k)
        {
            k -= (n - 1 - i);
            swap(s[i], s[n - 1]);
        }

        i = 0;
        while (i < n - 1 and s[i] != '1')
            i++;
        if (i < n - 1 and s[i] == '1' and i <= k)
        {
            k -= i;
            swap(s[i], s[0]);
        }
        // cerr << s << endl;

        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            ans += (10 * (s[i] - '0') + (s[i + 1] - '0'));
        }
        cout << ans << endl;
    }
    return 0;
}