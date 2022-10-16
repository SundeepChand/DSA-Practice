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
        v[n - 1] = n;
        v[n - 2] = n - 1;

        if (n % 2 == 1)
        {
            v[0] = 1;
            for (int i = 1; i < n - 2; i++)
            {
                v[i] = n - 1 - i;
            }
        }
        else
        {
            for (int i = 0; i < n - 2; i++)
            {
                v[i] = n - 2 - i;
            }
        }
        for (int x : v)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}