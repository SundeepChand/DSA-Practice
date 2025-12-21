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
        int n, k, b, s;
        cin >> n >> k >> b >> s;

        double f = (double)(s) / k - b;

        if (s < k * b or s > k * b + (k - 1) * n)
            cout << -1;
        else
        {
            vector<int> v(n);
            v[0] = k * b;

            int sum = v[0];
            for (int i = 0; i < n; i++)
            {
                int diff = min(s - sum, k - 1);
                v[i] += diff;
                sum += diff;
            }
            for (int x : v)
                cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}