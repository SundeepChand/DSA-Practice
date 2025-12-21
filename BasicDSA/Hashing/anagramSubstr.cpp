#include <bits/stdc++.h>
using namespace std;

int solve(string s)
{
    int n = s.length();

    unordered_map<int, int> u;
    for (int i = 0; i < n; i++)
    {
        int ctr = 0;
        for (int j = i; j < n; j++)
        {
            ctr += (s[j] - 'a' + 1);
            u[ctr]++;
        }
    }

    int ans = 0;
    for (auto it = u.begin(); it != u.end(); it++)
    {
        ans += ((it->second) * (it->second - 1)) / 2;
    }
    return ans;
}

int main()
{
    // string s = "abba";
    // string s = "xyyx";
    // string s = "geeg";
    string s = "geek";
    cout<<solve(s)<<endl;
    return 0;
}