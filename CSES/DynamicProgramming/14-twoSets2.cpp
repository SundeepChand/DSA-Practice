#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
typedef long long ll;

/*
// Here we try to find all the pairs twice and then divide it by 2. However, this solution gives WA :(
ll dp[501][200000];
int solve(ll n, ll sum, ll cur)
{
    if (cur == sum - cur)
        return 1;
    if (n < 1)
        return 0;
    if (dp[n][cur] != -1)
        return dp[n][cur];

    int ans = 0;
    if (n + cur <= sum - (n + cur))
        ans = (ans + solve(n - 1, sum, cur + n)) % MOD;
    ans = (ans + solve(n - 1, sum, cur)) % MOD;
    return dp[n][cur] = (solve(n - 1, sum, cur + n) + solve(n - 1, sum, cur)) % MOD;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ll n;
    cin >> n;

    ll sum = (n * (n + 1)) / 2;
    memset(dp, -1, sizeof(dp));
    cout << (solve(n, sum, 0) / 2) << endl;
    return 0;
}
*/

// Here we take all the numbers from 1, 2.. n -1. This way, we will count only the partitions not containing 'n'. And hence, count all the partitions only once. This works fine
int dp[500][130000];
int solve(ll n, ll sum, ll cur)
{
    if (cur == sum - cur)
        return 1;
    if (n < 1)
        return 0;
    if (dp[n][cur] != -1)
        return dp[n][cur];

    int ans = 0;
    if (n + cur <= sum - (n + cur))
        ans = (ans + solve(n - 1, sum, cur + n)) % MOD;
    ans = (ans + solve(n - 1, sum, cur)) % MOD;
    return dp[n][cur] = ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ll n;
    cin >> n;

    ll sum = (n * (n + 1)) / 2;
    memset(dp, -1, sizeof(dp));
    cout << solve(n - 1, sum, 0) << endl;
    return 0;
}
