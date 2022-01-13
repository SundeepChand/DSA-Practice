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

        string u = "";
        u += s[0];
        int i = 1;
        bool flag = false;
        for (i = 1; i < n; i++)
        {
            if (!flag && s[i] >= s[i - 1])
                break;
            else if (flag && s[i] > s[i - 1])
                break;
            u += s[i];
            flag = true;
        }
        string pre = u;
        reverse(u.begin(), u.end());
        cout << (pre + u) << endl;
    }
    return 0;
}