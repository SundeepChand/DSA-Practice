#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int numDivisible(int l, int r, vector<int> arr)
{
    int n = arr.size();

    int ans = 0;
    for (int i = 1; i < (1 << n); i++)
    {
        int lcm = 0;
        for (int j = i, k = 0; j > 0; j >>= 1, k++)
        {
            if (j & 1)
            {
                if (lcm == 0)
                    lcm = arr[k];
                else
                    lcm = lcm * arr[k] / __gcd(lcm, arr[k]);
            }
        }
        int val = (r / lcm - l / lcm) + ((l % lcm) == 0);
        if (__builtin_popcount(i) % 2 == 0)
            ans -= val;
        else
            ans += val;
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

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        int l, r;
        cin >> l >> r;

        cout << numDivisible(l, r, v) << endl;
    }
    return 0;
}