#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[2001][2001];
int solve(string &s, int i, int k, int &m)
{
    if (i < 0)
    {
        if (k == 0)
            return 1;
        return 0;
    }
    if (k < 0)
        return 0;
    if ((s[i] - '0') % 2 == 0)
        return 0;
    if (dp[i][k] != -1)
        return dp[i][k];

    int ans = 0;
    for (int j = i - m; j >= 0; j--)
    {
        if ((s[j] - '0') % 2 == 0)
            ans = (ans + solve(s, j - 1, k - 1, m)) % MOD;
    }
    return dp[i][k] = ans;
}

int getAns(string &s, int n, int m, int k)
{
    memset(dp, -1, sizeof(dp));
    return solve(s, n - 1, k - 1, m);
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    string s;
    cin >> s;

    cout << getAns(s, n, m, k) << endl;
    return 0;
}