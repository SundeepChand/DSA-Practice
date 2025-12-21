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
    // cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n = 1e18;
    for (int i = 2; i <= 26; i++)
    {
        cout << "? " << 1 << " " << i << endl;
        fflush(stdout);
        int res1;
        cin >> res1;
        if (res1 == 0)
            return 0;

        cout << "? " << i << " " << 1 << endl;
        fflush(stdout);
        int res2;
        cin >> res2;
        if (res2 == 0)
            return 0;

        if (res1 == -1)
        {
            n = i - 1;
            break;
        }
        else if (res1 != res2)
        {
            n = res1 + res2;
            break;
        }
    }

    cout << "! " << n << endl;
    fflush(stdout);

    return 0;
}