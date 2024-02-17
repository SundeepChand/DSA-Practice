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

        vector<vector<int>> v(n, vector<int>(3));
        set<vector<int>> start, end;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i][0] >> v[i][1] >> v[i][2];
            start.insert({v[i][0], v[i][2], v[i][1]});
            end.insert({-v[i][1], v[i][2], v[i][0]});

            auto a = *start.begin(), b = *end.begin();
            b[0] = -b[0];
            if (make_pair(a[0], a[2]) == make_pair(b[2], b[0]))
            {
                // Same intervals
                cout << min(a[1], b[1]);
            }
            else if (a[0] == b[2])
            {
                if (a[2] > b[0])
                    cout << a[1];
                else
                    cout << b[1];
            }
            else if (b[0] == a[2])
            {

                if (a[0] < b[2])
                    cout << a[1];
                else
                    cout << b[1];
            }
            else
                cout << (a[1] + b[1]);
            cout << endl;
        }
    }
    return 0;
}