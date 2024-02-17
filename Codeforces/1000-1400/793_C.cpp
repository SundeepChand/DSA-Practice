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

        vector<int> v(n), in(n);
        for (int i = 0; i < n; i++)
        {
            cin >> in[i];
        }
        sort(in.begin(), in.end());

        int l = 0, r = n - 1;
        for (int i = 0; i < n; i++)
        {
            int x = in[i];
            if (i % 2 == 0)
                v[l++] = x;
            else
                v[r--] = x;
        }

        // for (int x : v)
        //     cerr << x << " ";
        // cerr << endl;

        int prev = -1, ans1 = 0, ans2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] > prev)
            {
                prev = v[i];
                ans1++;
            }
        }

        prev = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (v[i] > prev)
            {
                prev = v[i];
                ans2++;
            }
        }

        if (n == 1)
            cout << 1 << endl;
        else
            cout << min(ans1, ans2) << endl;
    }
    return 0;
}