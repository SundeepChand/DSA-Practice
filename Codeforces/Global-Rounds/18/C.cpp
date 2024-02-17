#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int diff(string a, string b)
{
    int ctr = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if ((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1'))
            ctr++;
    }
    return ctr;
}

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

        string a, b;
        cin >> a >> b;

        int na = 0, nb = 0;
        string c;
        for (char x : a)
        {
            if (x == '1')
            {
                na++;
                c.push_back('0');
            }
            else
                c.push_back('1');
        }
        for (char x : b)
            if (x == '1')
                nb++;

        if (na != nb)
        {
            cout << -1 << endl;
            continue;
        }

        int ans = diff(a, b);
        for (int i = 0; i < n; i++)
        {
            if (a[i] == '1')
            {
                c[i] = '1';
                ans = min(ans, diff(c, b));
                c[i] = '0';
            }
        }
        cout << ans << endl;
    }
    return 0;
}