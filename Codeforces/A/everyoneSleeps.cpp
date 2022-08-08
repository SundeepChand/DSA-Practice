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
        int n, h, m;
        cin >> n >> h >> m;

        int vlad_min = 60 * h + m;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            int hi, mi, cur_min;
            cin >> hi >> mi;
            cur_min = 60 * hi + mi;
            v[i] = cur_min;
        }

        sort(v.begin(), v.end());

        auto idx = lower_bound(v.begin(), v.end(), vlad_min) - v.begin();
        int diff;
        if (idx == v.size())
            diff = v[0] - vlad_min + 24 * 60;
        else
            diff = v[idx] - vlad_min;

        int ah = diff / 60, am = diff - ah * 60;
        cout << ah << " " << am << endl;
    }
    return 0;
}