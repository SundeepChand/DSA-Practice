#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        vector<int> freq(26, 0);

        for (char x : s)
        {
            freq[x - 'a']++;
        }

        for (int i = 0; i < s.length(); i++)
        {
            char cur_char = s[i];
            if (freq[cur_char - 'a'] == 1)
                return i;
        }
        return -1;
    }
};