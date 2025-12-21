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

        vector<int> v(n);
        bool allOdd = 1, allEven = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];

            if (v[i] % 2)
                allEven = false;
            else
                allOdd = false;
        }

        if (allEven)
            cout << "NO";
        else if (allOdd)
        {
            if (n % 2 == 1)
                cout << "YES";
            else
                cout << "NO";
        }
        else
            cout << "YES";
        cout << endl;
    }
    return 0;
}