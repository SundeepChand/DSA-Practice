#include <bits/stdc++.h>
using namespace std;

int dp[501][501];
int solve(int a, int b)
{
    if (a == b)
        return 0;
    if (a < b)
        swap(a, b);
    if (dp[a][b] != -1)
        return dp[a][b];
    int ans = INT_MAX;
    for (int i = 1; i < a; i++)
    {
        ans = min(ans, 1 + solve(i, b) + solve(a - i, b));
    }
    for (int i = 1; i < b; i++)
    {
        ans = min(ans, 1 + solve(i, a) + solve(b - i, a));
    }
    return dp[a][b] = ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int a, b;
    cin >> a >> b;

    memset(dp, -1, sizeof(dp));
    cout << solve(a, b) << endl;
    return 0;
}