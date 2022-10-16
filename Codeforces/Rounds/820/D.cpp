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
    /*
    6
    8 9 3 2 4 5
    5 1 3 4 5 10
    -3 -8 0 2 1 5

    4
    1 2 3 4
    1 1 2 2
    0 -1 -1 -2

    6
    5 4 2 1 8 100
    1 1 1 1 1 200
    -4 -3 -1 0 -7 100

    6
    1 4 1 2 4 2
    1 3 3 2 3 4
    0 -1 2 0 -1 2

    -1 -1 0 0 2 2


    */
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

        vector<int> x(n), y(x);
        vector<int> diff(n);
        multiset<int> st1;
        multiset<int, greater<int>> st2;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> y[i];
            int d = y[i] - x[i];
            if (d < 0)
                st1.insert(-d);
            else
                st2.insert(d);
            sum += d;
        }
        // cerr << sum << " " << st1.size() << " " << st2.size() << endl;

        // if (sum < 0)
        // {
        //     cout << 0 << endl;
        //     continue;
        // }

        int ans = 0;
        while (st2.size())
        {
            auto front = *st2.begin();
            st2.erase(st2.begin());
            // cerr << front;

            auto it = st1.upper_bound(front);
            if (it == st1.begin())
            {
                if (st2.size())
                {
                    auto last = st2.end();
                    last--;
                    // cerr << " " << (*last) << endl;
                    st2.erase(last);
                }
                else
                    break;
            }
            else
            {
                it--;
                // cerr << " " << (*it);
                st1.erase(it);
            }
            // cerr << endl;
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}