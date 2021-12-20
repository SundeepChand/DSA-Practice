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
        string s;
        cin >> s;

        int n = s.length();
        if (n % 2 == 1)
        {
            cout << "NO";
        }
        else
        {
            int i = 0, j = n / 2;
            while (j < n && s[i] == s[j])
            {
                i++, j++;
            }
            if (j >= n)
                cout << "YES";
            else
                cout << "NO";
        }
        cout << endl;
    }
    return 0;
}