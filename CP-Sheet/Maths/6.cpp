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
        vector<int> v(3);
        cin >> v[0] >> v[1] >> v[2];

        sort(v.begin(), v.end());

        if (v[1] != v[2])
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            cout << v[2] << " " << v[0] << " " << v[0] << endl;
        }
    }
    return 0;
}