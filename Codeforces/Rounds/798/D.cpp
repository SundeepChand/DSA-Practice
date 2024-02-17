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
        int n, m;
        cin >> n >> m;

        vector<string> v(n);
        int minX = n, maxX = -1, minY = n, maxY = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            for (int j = 0; j < m; j++)
            {
                if (v[i][j] == 'B')
                {
                    minX = min(minX, j);
                    maxX = max(maxX, j);
                    minY = min(minY, i);
                    maxY = max(maxY, i);
                }
            }
        }

        int ansX = (minX + maxX) / 2, ansY = (maxY + minY) / 2;
        ansX++, ansY++;
        cout << ansY << " " << ansX << endl;
    }
    return 0;
}