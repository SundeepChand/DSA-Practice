#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        int idx = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] < s[idx])
            {
                idx = i;
            }
        }
        cout << s[idx] << " ";
        for (int i = 0; i < s.length(); i++)
        {
            if (i != idx)
                cout << s[i];
        }
        cout << endl;
    }
    return 0;
}