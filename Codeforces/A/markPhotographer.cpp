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
        int n, x;
        cin >> n >> x;

        vector<int> v(2 * n);
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        int i = 0, j = n;
        bool flag = true;
        while (j < 2 * n)
        {
            if (v[j++] - v[i++] < x)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}