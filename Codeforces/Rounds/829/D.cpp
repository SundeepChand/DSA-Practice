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

    int n, x;
    cin >> n >> x;

    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;

        mp[v]++;
    }

    bool flag = true;
    for (auto i : mp)
    {
        if (i.first >= x)
            break;

        if (i.second % (i.first + 1) != 0)
        {
            flag = false;
            break;
        }
        mp[i.first + 1] += i.second / (i.first + 1);
    }
    if (flag)
        cout << "Yes";
    else
        cout << "No";
    cout << endl;

    return 0;
}