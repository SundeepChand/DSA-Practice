#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestMultipleOfThree(vector<int> &digits)
    {
        int n = digits.size(), sum = 0;

        vector<int> ctr(10, 0);
        for (int x : digits)
        {
            sum += x;
            ctr[x]++;
        }

        if (sum % 3 != 0)
        {
            // try removing a single no
            int a = (sum % 3 == 1 ? 1 : 2), b = (sum % 3 == 1 ? 2 : 1);
            bool flag = false;
            for (int i = a; i < 10; i += 3)
            {
                if (ctr[i] > 0)
                {
                    ctr[i]--, flag = true;
                    break;
                }
            }
            if (!flag)
            {
                // remove 2 nos
                int rem = 2;
                for (int i = b; i < 10; i += 3)
                {
                    while (rem > 0 && ctr[i] > 0)
                        ctr[i]--, rem--;
                    if (rem == 0)
                        break;
                }
            }
        }
        string ans = "";
        for (int i = 9; i >= 0; i--)
            ans += string(ctr[i], '0' + i);
        if (ans[0] == '0')
            return "0";
        return ans;
    }
};