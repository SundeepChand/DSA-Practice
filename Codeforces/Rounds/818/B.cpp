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
        int n, k, r, c;
        cin >> n >> k >> r >> c;

        vector<vector<char>> v(n, vector<char>(n, '.'));
        r--, c--;
        v[r][c] = 'X';

        for (int i = 0; i < n; i++)
        {
            int j = (c + r - i + n) % n;
            do
            {
                v[i][j] = 'X';
                j = (j + k) % n;
            } while (j != (c + r - i + n) % n);
        }

        for (auto x : v)
        {
            for (auto y : x)
                cout << y;
            cout << endl;
        }
    }
    return 0;
}