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

        vector<int> a(n);
        int sum = 0;
        bool nextCycle = false, poss = true;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            if (sum <= 0)
                nextCycle = true;
            if (nextCycle and sum != 0)
                poss = false;
        }

        if (sum == 0 and poss)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}