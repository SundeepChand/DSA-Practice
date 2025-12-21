#include <bits/stdc++.h>
using namespace std;

string longestCommonSubsequence(string text1, string text2) {
    int n = text1.size(), m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string lcs = "";
    // Reconstruct the lcs
    int i = n, j = m;
    while (i > 0 && j > 0 && dp[i][j] > 0)
    {
        if (text1[i - 1] == text2[j - 1])
        {
            lcs = text1[i - 1] + lcs;
            i--, j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    cout<<"\nTable:\n";
    for (auto x: dp)
    {
        for (auto y: x)
        {
            cout<<y<<", ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    return lcs;
}

int main()
{
    cout<<longestCommonSubsequence("abcde", "ace")<<endl;
    cout<<longestCommonSubsequence("abc", "def")<<endl;
    return 0;
}