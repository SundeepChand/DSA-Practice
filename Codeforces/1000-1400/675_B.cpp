#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int getMedian(int a, int b, int c, int d)
{
    int arr[] = {a, b, c, d};
    sort(arr, arr + 4);
    return (arr[1] + arr[2]) / 2;
}

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
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> v[i][j];
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int nr = n - 1 - i, nc = m - 1 - j;
                int a = v[i][j], b = v[nr][j], c = v[i][nc], d = v[nr][nc];
                int med = getMedian(a, b, c, d);
                if (nr != i and nc != j)
                    ans += (abs(a - med) + abs(b - med) + abs(c - med) + abs(d - med));
                else if (nr == i and nc != j)
                    ans += (abs(a - med) + abs(c - med));
                else if (nr != i and nc == j)
                    ans += (abs(a - med) + abs(b - med));
                v[i][j] = v[nr][j] = v[i][nc] = v[nr][nc] = med;
            }
        }
        cout << ans << endl;
    }
    return 0;
}