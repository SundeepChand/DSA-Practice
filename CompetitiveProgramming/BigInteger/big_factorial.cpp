#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> multiply(vector<int> res, int n)
    {
        vector<int> ans;
        int carry = 0;
        for (int i = 0; i < res.size(); i++)
        {
            int mult = res[i] * n + carry;
            ans.push_back(mult % 10);
            carry = mult / 10;
        }
        while (carry)
        {
            ans.push_back(carry % 10);
            carry /= 10;
        }
        return ans;
    }

    string factorial(int N)
    {
        vector<int> res = {1};
        for (int i = 1; i <= N; i++)
        {
            res = multiply(res, i);
        }
        reverse(res.begin(), res.end());
        string ans = "";
        for (auto x : res)
        {
            ans.push_back(x + '0');
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.factorial(5) << endl;
    cout << s.factorial(7) << endl;
    cout << s.factorial(10) << endl;
    cout << s.factorial(100) << endl;
    return 0;
}