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
        int n;
        cin >> n;

        vector<string> v(n - 2);
        for (int i = 0; i < (n - 2); i++)
        {
            cin >> v[i];
        }

        string ans = v[0];
        for (int i = 1; i < (n - 2); i++)
        {
            if (v[i][0] == ans[ans.length() - 1])
            {
                ans += v[i][1];
            }
            else
            {
                ans += v[i];
            }
        }
        if (ans.length() == (n - 1))
        {
            ans += 'a';
        }
        cout << ans << endl;
    }
    return 0;
}