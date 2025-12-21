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

    // Sort and  check with Timru

    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        sort(s.begin(), s.end());

        cerr << s << endl;

        if (s == "Timru")
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
}