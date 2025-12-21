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
        int n, l, r;
        cin >> n >> l >> r;

        vector<int> ans;
        for (int i = 1; i <= n; i++)
        {
            int val = ceil(double(l) / i) * i;
            if (val > r)
                break;
            ans.push_back(val);
        }
        if (ans.size() < n)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for (int x : ans)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}