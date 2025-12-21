#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isDigit(char c)
    {
        return c >= '0' && c <= '9';
    }
    string decodeString(string s)
    {
        string ans = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (isDigit(s[i]))
            {
                // start of a repeating pattern
                int n = 0;
                while (isDigit(s[i]))
                {
                    n = 10 * n + (s[i] - '0');
                    i++;
                }
                // we encounter '['
                string pattern = "";
                i++;
                int ct = 0;
                while (s[i] != ']' || ct)
                {
                    if (s[i] == '[')
                        ct++;
                    else if (s[i] == ']')
                        ct--;
                    pattern += s[i];
                    i++;
                }
                // we reach ']'

                // recursively decode pattern
                pattern = decodeString(pattern);
                for (int j = 0; j < n; j++)
                    ans += pattern;
            }
            else
                ans += s[i];
        }
        return ans;
    }
};