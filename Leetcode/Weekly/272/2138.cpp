#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.length();
        string cur = "";
        for (int i = 0; i < n; i++)
        {
            cur += s[i];
            if (cur.length() == k)
            {
                ans.push_back(cur);
                cur = "";
            }
        }
        if (cur != "")
        {
            int x = cur.length();
            while (x < k)
            {
                cur.push_back(fill);
                x++;
            }
            ans.push_back(cur);
        }
        return ans;
    }
};