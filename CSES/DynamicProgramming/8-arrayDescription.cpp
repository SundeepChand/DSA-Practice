#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

vector<int> all;
int solveBruteForce(vector<int> &v, int i, int m)
{
    if (i < 0)
    {
        return 1;
    }

    int n = v.size();
    int ans = 0;

    int l = 0, r = 0;
    if (i < n - 1)
        r = v[i + 1];
    if (i > 0)
        l = v[i - 1];
    if (v[i] == 0)
    {
        for (auto x : all)
        {
            if (
                (l != 0 && abs(l - x) <= 1 && r != 0 && abs(r - x) <= 1) || (l == 0 && abs(r - x) <= 1) || (r == 0 && abs(l - x) <= 1) || (l == 0 && r == 0))
            {
                v[i] = x;
                ans = (ans + solveBruteForce(v, i - 1, m)) % MOD;
                v[i] = 0;
            }
        }
    }
    else
    {
        if ((l != 0 && abs(l - v[i]) > 1) || (r != 0 && abs(r - v[i]) > 1))
            return 0;
        ans = solveBruteForce(v, i - 1, m);
    }
    return ans;
}

int solveBottomUp(vector<int> &v, int m, int n)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0)
            {
                if (v[i] == 0)
                    dp[i][j] = 1;
                else if (j + 1 == v[i])
                    dp[i][j] = 1;
            }
            else
            {
                if (v[i] == 0)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                    if (j > 0)
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                    if (j < m - 1)
                        dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
                }
                else
                {
                    if (j + 1 == v[i])
                    {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                        if (j > 0)
                            dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                        if (j < m - 1)
                            dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int j = 0; j < m; j++)
    {
        ans = (ans + dp[n - 1][j]) % MOD;
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 1; i <= m; i++)
    {
        all.push_back(i);
    }

    // cout << solveBruteForce(v, n - 1, m) << endl;
    cout << solveBottomUp(v, m, n) << endl;

    return 0;
}