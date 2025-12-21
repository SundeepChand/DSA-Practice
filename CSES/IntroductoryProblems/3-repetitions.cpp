#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.length(), ans = 1;
    for (int i = 1; i < n; i++)
    {
        int cur = 1;
        while (i < n && s[i] == s[i - 1])
        {
            cur++;
            i++;
        }
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}