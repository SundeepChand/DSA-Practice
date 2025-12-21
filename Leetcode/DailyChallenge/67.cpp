#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string ans = "";
        int i = 0, j = 0;
        int carry = 0;
        while (i < a.length() && j < b.length())
        {
            int n1 = a[i] - '0', n2 = b[i] - '0';
            int s = n1 + n2 + carry;
            if (s >= 2)
                carry = 1, s -= 2;
            else
                carry = 0;
            ans += (s + '0');
            i++, j++;
        }
        while (i < a.length())
        {
            int n1 = a[i] - '0';
            int s = n1 + carry;
            if (s >= 2)
                carry = 1, s -= 2;
            else
                carry = 0;
            ans += (s + '0');
            i++;
        }
        while (j < b.length())
        {
            int n1 = b[j] - '0';
            int s = n1 + carry;
            if (s >= 2)
                carry = 1, s -= 2;
            else
                carry = 0;
            ans += (s + '0');
            j++;
        }
        if (carry)
            ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};