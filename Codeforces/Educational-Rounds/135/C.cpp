#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int ndigits(int n)
{
    int ans = 0;
    while (n)
    {
        n /= 10;
        ans++;
    }
    return ans;
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

        multiset<int, greater<int>> a, b;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a.insert(x);
        }
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            b.insert(x);
        }

        int ans = 0;
        while (!a.empty())
        {
            auto c1 = *a.begin(), c2 = *b.begin();
            a.erase(a.begin());
            b.erase(b.begin());
            if (c1 > c2)
            {
                a.insert(ndigits(c1));
                b.insert(c2);
                ans++;
            }
            else if (c1 < c2)
            {
                a.insert(c1);
                b.insert(ndigits(c2));
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}