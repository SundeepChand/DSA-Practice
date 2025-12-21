#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool winnerSquareGame(int n)
    {
        vector<bool> dp(n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            bool win = false;
            for (int j = sqrt(i); j > 0; j--)
            {
                if (dp[i - (j * j)] == 0)
                {
                    win = true;
                    break;
                }
            }
            dp[i] = win;
        }
        return dp[n];
    }
};