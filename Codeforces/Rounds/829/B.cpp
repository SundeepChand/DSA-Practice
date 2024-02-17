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
        int val = ceil(double(n) / 2);
        for (int i = 0; i < n; i += 2)
        {
            v[i] = val--;
        }

        val = n;
        for (int i = 1; i < n; i += 2)
        {
            v[i] += val--;
        }

        for (int x : v)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}