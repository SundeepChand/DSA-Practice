#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int derangement(int n)
{
    vector<int> dp(n + 1);
    dp[0] = 1, dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = ((i - 1) * ((dp[i - 2] + dp[i - 1]) % MOD)) % MOD;
    }
    return dp[n];
}

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
    cout << derangement(n) << endl;
    return 0;
}