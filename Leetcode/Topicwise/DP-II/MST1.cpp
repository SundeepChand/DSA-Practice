#include <bits/stdc++.h>
using namespace std;

int dp[20000001];

int solve(int n)
{
    if (n <= 1)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    int ans = INT_MAX;
    if (n % 2 == 0)
        ans = min(ans, 1 + solve(n / 2));
    if (n % 3 == 0)
        ans = min(ans, 1 + solve(n / 3));
    ans = min(ans, 1 + solve(n - 1));
    return dp[n] = ans;
}

int main()
{
    int t;
    cin >> t;
    int tot = t;
    memset(dp, -1, sizeof(dp));

    while (t--)
    {
        int n;
        cin >> n;

        cout << "Case " << (tot - t) << ": " << solve(n) << endl;
    }
    return 0;
}