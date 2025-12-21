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

        vector<int> v(n);
        int i = n - 1, maxVal = n - 1;
        bool flag = true;
        while (i >= 0)
        {
            int nextSq = ceil(sqrt(i));
            nextSq *= nextSq;
            int diff = nextSq - i;
            if (diff > maxVal)
            {
                flag = false;
                break;
            }
            int nextVal = diff - 1;
            while (i >= 0 and diff <= maxVal)
            {
                v[i] = diff;
                i--;
                diff++;
            }
            maxVal = nextVal;
        }

        if (!flag)
        {
            cout << -1;
        }
        else
        {
            for (int x : v)
                cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}