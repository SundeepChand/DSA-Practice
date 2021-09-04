#include <bits/stdc++.h>
using namespace std;

int maxProfitTDUtil(const vector<int> &p, int i, int j, vector<vector<int>> &dp)
{
    if (j < i)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int n = p.size();
    int len = (n - j + i);
    int t1 = p[i] * len + maxProfitTDUtil(p, i + 1, j, dp);
    int t2 = p[j] * len + maxProfitTDUtil(p, i, j - 1, dp);
    return (dp[i][j] = max(t1, t2));
}

int maxProfitTD(const vector<int> &p)
{
    int n = p.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    return maxProfitTDUtil(p, 0, n - 1, dp);
}

int maxProfitBU(const vector<int> &p)
{
    int n = p.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
            {
                // Base case
                dp[i][j] = n * p[i];
            }
            else
            {
                int len = (n - j + i);
                dp[i][j] = max(
                    p[i] * len + dp[i + 1][j],
                    p[j] * len + dp[i][j - 1]
                );
            }
        }
    }

    // Backtrack on the DP array to re-construct the solution.
    vector<string> steps;
    int i = 0, j = n - 1;
    while (i != j)
    {
        int len = (n - j + i);
        int t1 = p[i] * len + dp[i + 1][j];
        int t2 = p[j] * len + dp[i][j - 1];
        if (t1 > t2)
        {
            steps.push_back("beg");
            i = i + 1;
        }
        else
        {
            steps.push_back("end");
            j = j - 1;
        }
    }
    steps.push_back("beg");

    for (string s: steps)
    {
        cout<<s<<", ";
    }
    cout<<endl;

    return dp[0][n - 1];
}

int main()
{
    // vector<int> p {2, 4, 6, 2, 5};
    // vector<int> p {2, 5, 3};
    vector<int> p {2, 3, 5, 1, 4};

    cout<<maxProfitTD(p)<<endl;
    cout<<maxProfitBU(p)<<endl;
    return 0;
}