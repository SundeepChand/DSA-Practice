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
        int n, m;
        cin >> n >> m;

        string s1, s2;
        cin >> s1 >> s2;

        if (m > n)
        {
            cout << "NO" << endl;
            continue;
        }
        if (m == n)
        {
            if (s1 == s2)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
            continue;
        }

        int i = n - 1, j = m - 1;
        while (i >= 0 and j >= 0 and s1[i] == s2[j])
        {
            i--, j--;
        }

        if (j < 0)
        {
            cout << "YEs" << endl;
            continue;
        }
        else if (j > 0)
        {
            cout << "No" << endl;
            continue;
        }

        while (i >= 0 and s1[i] != s2[0])
        {
            if (s1[i] == s2[0])
                break;
            i--;
        }
        if (i >= 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}