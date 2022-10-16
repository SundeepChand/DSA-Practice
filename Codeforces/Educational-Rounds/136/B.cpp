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

        vector<int> d(n);
        for (int i = 0; i < n; i++)
        {
            cin >> d[i];
        }

        vector<int> a(n);
        a[0] = d[0];

        bool poss = true;
        for (int i = 1; i < n; i++)
        {
            int prev = a[i - 1];
            if (d[i] == 0 or d[i] > prev)
                a[i] = prev + d[i];
            else
            {
                poss = false;
                break;
            }
        }
        if (!poss)
            cout << -1;
        else
        {
            for (int x : a)
                cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}