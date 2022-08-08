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
        int n, s;
        cin >> n >> s;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        int i = 0, j = 0, curSum = 0;
        int l = -1, r = -1;

        while (j < n)
        {
            while (j < n and curSum + v[j] <= s)
            {
                curSum += v[j];
                j++;
            }
            if (curSum == s and j - i - 1 >= r - l)
                r = j - 1, l = i;

            while (i <= j and curSum >= s)
            {
                curSum -= v[i];
                i++;
            }
        }
        if (l == -1)
            cout << -1;
        else
            cout << (n - r + l - 1);
        cout << endl;
    }
    return 0;
}