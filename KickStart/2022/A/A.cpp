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

    int tc = t;

    while (t--)
    {
        string a, b;
        cin>>a>>b;

        int i = 0, j = 0, n = a.size(), m = b.size();

        int ans = 0;
        while (i < n && j < m)
        {
            if (a[i] == b[j])
                i++, j++;
            else
                j++, ans++;
        }

        cout<<"Case #"<<(tc - t)<<": ";
        if (i < n)
        {
            cout<<"IMPOSSIBLE";
        }
        else
        {
            ans += (m - j);
            cout<<ans;
        }
        cout<<endl;
    }
    return 0;
}