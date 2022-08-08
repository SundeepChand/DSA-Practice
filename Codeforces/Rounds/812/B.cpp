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

        vector<int> v(1);
        cin >> v[0];
        for (int i = 1; i < n; i++)
        {
            int x;
            cin >> x;
            if (x != v.back())
                v.push_back(x);
        }

        int valleys = 0;
        for (int i = 1; i < v.size() - 1; i++)
        {
            if (v[i] < v[i - 1] and v[i] < v[i + 1])
                valleys++;
        }
        if (valleys <= 0)
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
}