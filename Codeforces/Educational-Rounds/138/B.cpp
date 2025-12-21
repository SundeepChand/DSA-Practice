#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

bool cmp(pair<int, list<int>::iterator> &a, pair<int, list<int>::iterator> &b)
{
    return a.first < b.first;
}

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

        // list<int> a;
        // vector<pair<int, list<int>::iterator>> b(n);
        // for (int i = 0; i < n; i++)
        // {
        //     int x;
        //     cin >> x;
        //     a.push_back(x);
        // }

        // list<int>::iterator it = a.begin();
        // for (int i = 0; i < n; i++)
        // {
        //     cin >> b[i].first;
        //     b[i].second = it;
        //     it++;
        // }

        // sort(b.begin(), b.end(), cmp);

        // int ans = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     auto it = b[i].second;
        //     ans += *b[i].second;
        //     if (it != a.begin())
        //     {
        //         it--;
        //         *it += b[i].first;
        //         it++;
        //     }
        //     it++;
        //     if (it != a.end())
        //     {
        //         *it += b[i].first;
        //     }
        //     it--;

        //     a.erase(it);
        // }
        // cout << ans << endl;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int j = 0; j < n; j++)
            cin >> b[j];

        int i = 0, j = n - 1;
        int ans = 0;
        while (i <= j)
        {
            if (b[i] < b[j])
            {
                ans += a[i];
                if (i + 1 < n)
                    a[i + 1] += b[i];
                i++;
            }
            else
            {
                ans += a[j];
                if (j > 0)
                    a[j - 1] += b[j];
                j--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}