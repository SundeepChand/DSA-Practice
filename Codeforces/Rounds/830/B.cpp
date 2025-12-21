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

        int i = 0;
        while (i < n and s[i] == '0')
            i++;
        while (i < n and s[i] == '1')
            i++;

        int ans = i < n;
        i++;
        for (; i < n; i++)
        {
            if (s[i - 1] != s[i])
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}