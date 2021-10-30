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

    string s;
    cin >> s;

    string t = "hello";
    int i = 0;
    for (auto x : s)
    {
        if (tolower(x) == t[i])
            i++;
        if (i == 5)
            break;
    }
    if (i == 5)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
    return 0;
}