#include <bits/stdc++.h>
using namespace std;

class PalindromPartition
{
public:
    bool isPalindrome(string s, int i, int j)
    {
        while (i < j)
            if (s[i++] != s[j--])
                return false;
        return true;
    }
    int solve(string s, int i, int j)
    {
        if (isPalindrome(s, i, j))
            return 0;
        if (i >= j)
            return 0;

        int ans = INT_MAX;
        for (int k = i; k < j; k++)
        {
            int temp = 1 + solve(s, i, k) + solve(s, k + 1, j);
            ans = min(ans, temp);
        }
        return ans;
    }
    int minPartition(string s)
    {
        int n = s.length();
        return solve(s, 0, n - 1);
    }
};

class Solution
{
public:
    bool isPalindrome(string s, int i, int j)
    {
        while (i < j)
            if (s[i++] != s[j--])
                return false;
        return true;
    }

    set<vector<string>> ans;
    void solve(string s, int i, int j, vector<string> &v)
    {
        if (i > j)
        {
            ans.insert(v);
            return;
        }
        string cur = "";
        for (int k = i; k <= j; k++)
        {
            cur += s[k];
            if (isPalindrome(s, i, k))
            {
                v.push_back(cur);
                solve(s, k + 1, j, v);
                v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        int n = s.length();
        vector<string> v;
        solve(s, 0, n - 1, v);
        return vector<vector<string>>(ans.begin(), ans.end());
    }
};

int main()
{
    Solution p;
    string s = "nitik";
    vector<vector<string>> ans = p.partition(s);
    for (auto x : ans)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}