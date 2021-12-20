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

    cout.setf(ios::fixed);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        int last_unsorted = n - 1;
        while (last_unsorted >= 0 && v[last_unsorted] == last_unsorted + 1)
            last_unsorted--;

        long double proba = 1.0;
        for (int i = 0; i < m; i++)
        {
            int idx;
            long double prb;
            cin >> idx >> prb;
            if (idx > last_unsorted)
                proba *= (1.0 - prb);
        }

        if (last_unsorted < 0)
            cout << 1.0;
        else
            cout << (1 - proba);
        cout << endl;
    }
    return 0;
}