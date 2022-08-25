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

        vector<int> ans;
        int mult = 1;
        while (n)
        {
            if (n % 10)
                ans.push_back(mult * (n % 10));
            n /= 10;
            mult *= 10;
        }

        cout << ans.size() << endl;
        for (int x : ans)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}