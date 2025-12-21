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

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    bool flag = false;
    for (int i = 0; i < (1 << n); i++)
    {
        int j = i, k = 0;
        int tot = 0;
        while (k < n)
        {
            if (j & 1)
            {
                tot = ((tot - v[k]) + 360) % 360;
            }
            else
            {
                tot = (tot + v[k]) % 360;
            }
            k++;
            j >>= 1;
        }
        if (tot == 0)
        {
            flag = true;
            break;
        }
    }
    if (flag)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
    return 0;
}