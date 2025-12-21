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

        string ans = "";
        for (int i = n - 1; i >= 0;)
        {
            if (s[i] == '0')
            {
                int val = 10 * (s[i - 2] - '0') + (s[i - 1] - '0') - 1;
                ans += (val + 'a');
                i -= 3;
            }
            else
            {
                int val = s[i] - '0' - 1;
                ans += (val + 'a');
                i--;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    return 0;
}