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

        vector<vector<int>> v(n, vector<int>(m));
        bool allOnes = true;
        int ctr = 0;
        for (int i = 0; i < n; i++)
        {
            string cur;
            cin >> cur;
            for (int j = 0; j < m; j++)
            {
                v[i][j] = cur[j] - '0';
                if (v[i][j] == 0)
                    allOnes = false;
                else
                    ctr++;
            }
        }
        if (allOnes)
        {
            cout << (ctr - 2) << endl;
            continue;
        }

        bool hasSingleSided = false;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < m - 1; j++)
            {
                if (
                    (v[i][j] == 0 and v[i][j + 1] == 0) or
                    (v[i][j] == 0 and v[i + 1][j] == 0) or
                    (v[i + 1][j] == 0 and v[i + 1][j + 1] == 0) or
                    (v[i][j + 1] == 0 and v[i + 1][j + 1] == 0) or
                    (v[i][j] == 0 and v[i + 1][j + 1] == 0) or
                    (v[i + 1][j] == 0 and v[i][j + 1] == 0))
                    hasSingleSided = true;
            }
        }
        if (hasSingleSided)
            cout << ctr << endl;
        else
            cout << (ctr - 1) << endl;
    }
    return 0;
}