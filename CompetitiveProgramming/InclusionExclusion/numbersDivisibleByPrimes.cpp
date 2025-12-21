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

    int m, n;
    cin >> m >> n;

    vector<int> primes(n);
    for (int i = 0; i < n; i++)
    {
        cin >> primes[i];
    }

    int ans = 0;
    for (int i = 1; i < (1 << n); i++)
    {
        int lcm = 1, ctr = 0;
        for (int j = i, k = 0; j > 0; j >>= 1, k++)
        {
            if (j & 1)
            {
                lcm *= primes[k];
                ctr++;
            }
        }
        ans = ans + (ctr % 2 ? 1 : -1) * (m / lcm);
    }
    cout << ans << endl;
    return 0;
}