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

    vector<vector<int>> v(5, vector<int>(5));

    int r1 = -1, c1 = -1;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 1)
                r1 = i, c1 = j;
        }
    }
    cout << (abs(r1 - 2) + abs(c1 - 2)) << endl;
    return 0;
}