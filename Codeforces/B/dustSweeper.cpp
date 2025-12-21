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
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        bool flag = false;
        int moves = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i] > 0)
                flag = true;
            if (flag and v[i] == 0)
                moves++;
        }

        for (int i = 0; i < n - 1; i++)
        {
            moves += v[i];
        }
        cout << moves << endl;
    }
    return 0;
}