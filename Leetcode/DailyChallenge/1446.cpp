#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxPower(string s)
    {
        int n = s.length();
        if (n == 0)
            return 0;
        int ans = 1, cur = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
            {
                cur++;
            }
            else
            {
                cur = 1;
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};