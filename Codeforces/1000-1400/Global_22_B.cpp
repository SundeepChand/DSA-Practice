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
        int n, k;
        cin >> n >> k;

        vector<int> v(k);
        for (int i = 0; i < k; i++)
        {
            cin >> v[i];
        }

        if (k == 1)
            cout << "Yes";
        else
        {
            int first = v[1] - v[0];
            if (k < n and v[0] > (n - k + 1) * first)
                cout << "No";
            else
            {
                bool flag = true;
                if (k == n)
                    first = v[0];
                for (int i = 1; i < k; i++)
                {
                    if (v[i] - v[i - 1] < first)
                    {
                        flag = false;
                        break;
                    }
                    first = v[i] - v[i - 1];
                }
                if (flag)
                    cout << "Yes";
                else
                    cout << "No";
            }
        }
        cout << endl;
    }
    return 0;
}