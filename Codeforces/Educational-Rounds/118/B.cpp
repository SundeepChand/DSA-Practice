#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        unordered_set<int> u;
        bool one = false;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            u.insert(a[i]);
            if (a[i] == 1)
                one = true;
        }
        sort(a.begin(), a.end());
        if (one)
        {
            for (int i = 0; i < (n / 2); i++)
            {
                cout << a[i + 1] << " " << 1 << endl;
            }
            continue;
        }

        vector<pair<int, int>> ans;
        int i = 1;
        while (ans.size() < (n / 2))
        {
            int j = i;
            for (; ans.size() < (n / 2) && j < n; j++)
            {
                if (u.find(a[j] % a[j - i]) == u.end())
                {
                    ans.push_back({a[j], a[j - i]});
                }
                u.insert(a[j]);
            }
            i++;
        }
        for (auto x : ans)
        {
            cout << x.first << " " << x.second << endl;
        }
    }
    return 0;
}