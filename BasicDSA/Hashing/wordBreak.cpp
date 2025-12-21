#include <bits/stdc++.h>
using namespace std;

unordered_set<string> u;
unordered_map<int, int> dp;
int solve(string s, int i)
{
    int n = s.length();
    if (i >= n)
        return 0;
    
    if (dp.find(i) != dp.end())
        return dp[i];

    int ans = INT_MAX;
    for (int j = i; j < n; j++)
    {
        if (u.find(s.substr(i, j - i + 1)) != u.end())
        {
            int temp = solve(s, j + 1);
            if (temp != -1)
            {
                ans = min(ans, 1 + temp);
            }
        }
    }
    if (ans == INT_MAX)
        return (dp[i] = -1);
    return (dp[i] = ans);
}

int findMinBreaks(string s, vector<string> words)
{
    u = unordered_set<string>(words.begin(), words.end());
    return solve(s, 0) - 1;
}

int main()
{
    // vector<string> words = { "i", "like", "sam", "sung", "samsung", "mobile", "ice","cream", "icecream", "man", "go", "mango" };
    // string s = "ilikea";
    vector<string> words = { "the", "quickbrown", "fox", "quick", "brown" };
    string s = "thequickbrownfox";

    cout<<findMinBreaks(s, words)<<endl;
    return 0;
}