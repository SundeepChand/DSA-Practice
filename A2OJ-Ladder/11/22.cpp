#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        int x = s.length();
        if (x > 10)
        {
            cout << s[0] << (x - 2) << s[x - 1] << endl;
        }
        else
        {
            cout << s << endl;
        }
    }
    return 0;
}