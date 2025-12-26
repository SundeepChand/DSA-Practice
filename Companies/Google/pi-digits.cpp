// https://leetcode.com/discuss/post/6174969/google-phone-screen-swe3-sweiii-l4-banga-hmvw/
#include <bits/stdc++.h>
using namespace std;

// The mod based approach has a time complexity of O(num_digits), but log10 is handled by CPU's inbuilt
// instruction which makes it a true O(1) operation
int getNumDigits(int i)
{
    return log10(i) + 1;
}

vector<int> solveBrute(const string &s)
{
    int n = s.size();

    vector<int> res;

    for (int i = 0; i < n; i++)
    {
        int nDigits = getNumDigits(i + 1);

        string subStr = s.substr(i - nDigits + 1, nDigits);
        if (stoi(subStr) == i + 1)
        {
            res.push_back(i + 1);
        }
    }
    return res;
}

vector<int> solveSlidingWindow(const string &s)
{
    int n = s.size();

    vector<int> res;

    int curDigits = 1;
    int curValue = s[0] - '0';
    if (curValue == 1)
    {
        res.push_back(curValue);
    }
    for (int i = 1; i < n; i++)
    {
        int nDigits = getNumDigits(i + 1);

        if (nDigits > curDigits)
        {
            curDigits++;
            curValue = 10 * curValue + s[i] - '0';
        }
        else
        {
            curValue = 10 * curValue + s[i] - '0';
            curValue = curValue % int(pow(10, curDigits));
        }

        if (curValue == i + 1)
        {
            res.push_back(i + 1);
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--)
    {
        string pi;
        cin >> pi;

        vector<int> res = solveBrute(pi);
        for (int x : res)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}