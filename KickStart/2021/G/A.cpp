#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    int temp = t;

    while (t--)
    {
        ll n, d, c, m;
        cin >> n >> d >> c >> m;

        string s;
        cin >> s;

        int i;
        for (i = 0; i < n; i++)
        {
            if (s[i] == 'D' && d <= 0)
                break;
            if (s[i] == 'C' && c <= 0)
                break;
            if (s[i] == 'D')
            {
                d--;
                c += m;
            }
            else
            {
                c--;
            }
        }

        string ans;
        bool flag = false;
        while (i < n)
        {
            if (s[i] == 'D')
            {
                flag = true;
                break;
            }
            i++;
        }
        if (flag)
            ans = "NO";
        else
            ans = "YES";

        cout << "Case #" << (temp - t) << ": " << ans << endl;
    }
    return 0;
}