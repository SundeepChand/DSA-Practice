#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s1, s2;
        cin >> s1 >> s2;

        for (char &c : s1)
        {
            if (c == 'B' or c == 'G')
                c = '*';
        }

        for (char &c : s2)
        {
            if (c == 'B' or c == 'G')
                c = '*';
        }

        if (s1 == s2)
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
}