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
        int ne = 0, no = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] % 2 == 0)
                ne++;
            else
                no++;
        }

        bool flag = false;
        if (ne % 2 == 1)
        {
            // Bob starts with odd.
            if (no % 4 == 0 or (no - 1) % 4 == 0)
                flag = true;
        }

        // Alice starts with odd
        if ((no - 3) % 4 == 0 or (no - 4) % 4 == 0)
            flag = true;

        if (flag)
            cout << "Alice";
        else
            cout << "Bob";
        cout << endl;
    }
    return 0;
}