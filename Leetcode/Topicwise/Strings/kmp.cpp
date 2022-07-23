#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matchKMP(string &text, string &pattern)
{
    int n = text.size(), m = pattern.size();
    vector<vector<int>> matches;
    if (m == 0)
        return matches;

    vector<int> pi(m);
    pi[0] = 0;

    for (int i = 1; i < m; i++)
    {
        int j = i - 1;
        while (j > 0 and pattern[pi[j]] != pattern[i])
        {
            j = pi[j - 1];
        }
        pi[i] = 0;
        if (pattern[i] == pattern[pi[j]])
            pi[i] = 1 + pi[j];
    }

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (text[i] == pattern[j])
        {
            j++;
            if (j == m)
            {
                matches.push_back({i - m + 1, i});
                j = pi[j - 1];
            }
        }
        else
        {
            if (j > 0)
                j = pi[j - 1], i--;
        }
    }
    return matches;
}

int main()
{
    string text = "abbcdaabbcdaaabbccd";
    string pattern = "abbcd";

    vector<vector<int>> matches = matchKMP(text, pattern);

    for (auto x : matches)
        cout << "Found at " << x[0] << " " << x[1] << endl;
    return 0;
}