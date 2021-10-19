#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 1000000
#define MOD 1000000007

typedef long long ll;

int dp[MAX_SIZE + 1];

int solve(int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int ways = 0;
    for (int i = 1; i <= 6; i++)
    {
        if (i <= n)
            ways = (ways + solve(n - i)) % MOD;
    }
    return (dp[n] = ways);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));
    cout << solve(n) << endl;
    return 0;
}