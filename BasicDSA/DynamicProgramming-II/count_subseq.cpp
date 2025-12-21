#include <bits/stdc++.h>
using namespace std;

int countWaysTDUtil(const string &S1, const string &S2, int i, int j, vector<vector<int>> &dp)
{
    int n = S1.length(), m = S2.length();
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    if (S1[i] == S2[j])
    {
        ans += countWaysTDUtil(S1, S2, i - 1, j - 1, dp);
    }
    ans += countWaysTDUtil(S1, S2, i - 1, j, dp);
    return (dp[i][j] = ans);
}

int countWaysTD(string S1, string S2)
{
    int n = S1.length(), m = S2.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return countWaysTDUtil(S1, S2, n - 1, m - 1, dp);
}

int countWaysBU(string S1, string S2)
{
    int n = S1.length(), m = S2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    // Set the base values
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (j == 0)
                dp[i][j] = 1;
            else if (S1[i - 1] == S2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][m];
}

int main()
{
    cout<<countWaysTD("abcdce", "abc")<<endl; // Expected 2
    cout<<countWaysTD("geeksforgeeks", "gks")<<endl; // Expected 4

    cout<<countWaysBU("abcdce", "abc")<<endl; // Expected 2
    cout<<countWaysBU("geeksforgeeks", "gks")<<endl; // Expected 4
    return 0;
}