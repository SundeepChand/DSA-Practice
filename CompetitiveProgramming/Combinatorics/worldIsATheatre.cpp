#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int long double

int nCr(int n, int r)
{
    if (n - r < r)
        r = n - r;
    int ans = 1, d = 1;
    for (int i = 0; i < r; i++)
        ans *= (n - i), d *= (i + 1);
    ans /= d;
    return ans;
}

int solve(int n, int m, int t)
{
    int ans = 0;
    for (int i = 4; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            if (i + j == t)
                ans += nCr(n, i) * nCr(m, j);
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

    int n, m, t;
    cin >> n >> m >> t;

    cout.setf(ios::fixed);
    cout << setprecision(0) << solve(n, m, t) << endl;
    return 0;
}