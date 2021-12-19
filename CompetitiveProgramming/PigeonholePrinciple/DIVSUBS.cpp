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

        int a = -1, b = -1;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        for (int i = 1; i < n; i++)
            v[i] = v[i] + v[i - 1];

        int pos[n];
        memset(pos, -1, sizeof(pos));
        for (int i = 0; i < n; i++)
        {
            v[i] %= n;
            if (v[i] == 0)
            {
                a = 1, b = i + 1;
                break;
            }
            else if (pos[v[i]] != -1)
            {
                a = pos[v[i]] + 1, b = i + 1;
                break;
            }
            pos[v[i]] = i + 1;
        }
        cout << (b - a + 1) << endl;
        for (int i = a; i <= b; i++)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}