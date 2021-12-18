#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getDigitsLessThan(vector<string> &digits, string n)
    {
        return (lower_bound(digits.begin(), digits.end(), n) - digits.begin());
    }

    int getDigits(vector<string> &digits, int d, string n, int i)
    {
        if (i == n.length())
            return 1;

        int m = digits.size();
        string digit = "";
        digit += n[i];

        int ans = getDigitsLessThan(digits, digit) * pow(m, d - 1);

        if (find(digits.begin(), digits.end(), digit) != digits.end())
            ans += getDigits(digits, d - 1, n, i + 1);

        return ans;
    }
    int countNumbersWithDDigits(vector<string> &digits, int d, string n)
    {
        int m = digits.size();
        int ans = 1;
        if (d < n.length())
        {
            ans = pow(m, d);
        }
        else
        {
            ans = getDigits(digits, d, n, 0);
        }
        return ans;
    }
    int atMostNGivenDigitSet(vector<string> &digits, int n)
    {
        string num = to_string(n);

        int ans = 0;
        for (int i = 1; i <= num.length(); i++)
        {
            ans += countNumbersWithDDigits(digits, i, num);
        }
        return ans;
    }
};