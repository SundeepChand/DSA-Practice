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

    int n;
    cin >> n;

    string s;
    cin >> s;

    string ans = s;

    int i = 0;
    while (i < n and s[i] != '1')
        i++;

    string aux = s.substr(i, n - i - 1);
    cerr << s << endl
         << aux << endl;

    while (i < n and s[i] != '0')
        i++;

    for (int j = 0; i < n; j++, i++)
    {
        if (s[i] == '1' or aux[j] == '1')
            ans[i] = '1';
    }

    cout << ans << endl;
    return 0;
}