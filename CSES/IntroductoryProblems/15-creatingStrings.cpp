#include <bits/stdc++.h>
using namespace std;

set<string> solve(string s)
{
    set<string> res;
    int n = s.length();
    if (n <= 1)
    {
        res.insert(s);
        return res;
    }

    for (int i = 0; i < n; i++)
    {
        set<string> sub = solve(s.substr(0, i) + s.substr(i + 1, n - i));
        for (string x : sub)
        {
            res.insert(s[i] + x);
        }
    }
    return res;
}

int main()
{
    string s;
    cin >> s;

    sort(s.begin(), s.end());
    int n = s.length();

    set<string> res = solve(s);

    cout << res.size() << endl;
    for (auto x : res)
        cout << x << endl;
    return 0;
}