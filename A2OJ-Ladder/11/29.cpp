#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    int x = 0;
    while (t--)
    {
        string s;
        cin >> s;

        if (s[0] == '-' || s[1] == '-' || s[2] == '-')
            x--;
        else if (s[0] == '+' || s[1] == '+' || s[2] == '+')
            x++;
    }
    cout << x << endl;
    return 0;
}