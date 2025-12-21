#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

bool canSolve(vector<int> v, int i)
{
    int g = 0;
    v[i] = __gcd(v[i], i + 1);
    for (int j = 0; j < v.size(); j++)
    {
        g = __gcd(g, v[j]);
    }
    return g == 1;
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

        vector<int> v(n);
        int g = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            g = __gcd(g, v[i]);
        }

        if (g == 1)
            cout << 0;
        else
        {
            int ans = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                if (canSolve(v, i))
                {
                    ans = n - i;
                    break;
                }
            }
            cerr << ans << endl;
            ans = min(ans, 3LL);
            cout << ans;
        }
        cout << endl;
    }
    return 0;
}