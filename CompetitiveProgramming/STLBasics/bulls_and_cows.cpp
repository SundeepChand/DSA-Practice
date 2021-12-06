#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int n = secret.size(), m = guess.size();

        int bulls = 0, cows = 0;
        vector<int> s(10, 0), g(10, 0);
        for (int i = 0, j = 0; i < n || j < m; i++, j++)
        {
            if (i >= n)
            {
                continue;
            }
            else if (j >= m)
            {
                g[guess[j] - '0']++;
            }
            else if (secret[i] == guess[j])
            {
                bulls++;
            }
            else
            {
                s[secret[i] - '0']++;
                g[guess[j] - '0']++;
            }
        }
        for (int i = 0; i < 10; i++)
        {
            cows += min(s[i], g[i]);
        }
        string ans = "";
        ans += to_string(bulls);
        ans += "A";
        ans += to_string(cows);
        ans += "B";
        return ans;
    }
};