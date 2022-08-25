#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

vector<int> getLPS(const string &pat)
{
    int n = pat.size();
    vector<int> lps(n);

    lps[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int j = lps[i - 1];
        while (j > 0 and pat[j] != pat[i])
            j = lps[j - 1];
        lps[i] = j + (pat[j] == pat[i]);
    }
    return lps;
}

vector<int> KMP(const string &text, const string &pat)
{
    int n = text.size(), m = pat.size();
    if (m == 0 or n == 0)
        return vector<int>();

    vector<int> lps = getLPS(pat);
    vector<int> matches;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while (j > 0 and text[i] != pat[j])
            j = lps[j - 1];
        j += (text[i] == pat[j]);
        if (j == m)
        {
            matches.push_back(i - m + 1);
            j = lps[j - 1];
        }
    }
    return matches;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    string text, pat;
    cin >> text;
    cin >> pat;

    int m = pat.size();

    // Method 1: Append pat to the start of text with
    // some separator '#' that does not appear in both
    // pat and text. Then find the LPS. All those indices
    // where LPS is equal to m, are endings of places
    // where the patterns match.
    vector<int> lps = getLPS(pat + "#" + text);

    for (int i = m + 1; i < lps.size(); i++)
        if (lps[i] == m)
            cout << "Found match at " << (i - 2 * m) << endl;

    cout << endl
         << endl;

    // Method 2: Use the lps of pattern to implement matching.
    vector<int> pattern_indices = KMP(text, pat);
    for (auto i : pattern_indices)
        cout << "Found match at " << i << endl;
    return 0;
}