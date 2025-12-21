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
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        string s;
        cin >> s;

        int nz = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                nz++;
        }

        vector<pair<int, int>> ns;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0' && v[i] > nz)
                ns.push_back({v[i], i});
        }
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1' && v[i] <= nz)
            {
                int temp = v[i];
                v[i] = ns[j].first;
                v[ns[j].second] = temp;
                j++;
            }
        }
        for (int i = 0; i < n; i++)
            cout << v[i] << " ";
        cout << endl;
    }
    return 0;
}