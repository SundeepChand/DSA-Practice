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

        string s1, s2;
        cin >> s1 >> s2;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            a[i] = (s1[i] - '0');
        for (int i = 0; i < n; i++)
            b[i] = (s2[i] - '0');

        if (n == 1)
        {
            if ((a[0] == 0 and b[0] == 0) or (a[0] == 1 and b[0] == 0))
            {
                cout << "Yes" << endl;
                if (a[0] == 1)
                {
                    cout << 1 << endl;
                    cout << 1 << " " << 1 << endl;
                }
                else
                    cout << 0 << endl;
            }
            continue;
        }

        vector<int> flips(n, 0);
        vector<vector<int>> pos;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
                continue;
            int j = i;
            while (j < n and a[j] == 1)
            {
                j++;
            }
            pos.push_back({i, j - 1});
            if (i > 0)
            {
                flips[0]++, flips[i]--;
            }
            if (j < n)
            {
                flips[j]++;
            }
            i = j - 1;
        }

        // cerr << "Flips: ";
        // for (int i = 0; i < n; i++)
        //     cerr << flips[i] << " ";
        // cerr << endl;

        int curFlip = 0;
        for (int i = 0; i < n; i++)
        {
            curFlip += flips[i];
            if (curFlip % 2 == 1)
                b[i] = 1 - b[i];
        }

        bool flag = true;
        int prev = b[0];
        for (int i = 0; i < n; i++)
        {
            if (b[i] != prev)
                flag = false;
        }
        if (!flag)
            cout << "No" << endl;
        else
        {
            cout << "Yes" << endl;
            if (prev == 1)
            {
                pos.push_back({0, n - 1});
                pos.push_back({0, 0});
                pos.push_back({1, n - 1});
            }
            cout << pos.size() << endl;
            for (auto p : pos)
                cout << (p[0] + 1) << " " << (p[1] + 1) << endl;
        }
    }
    return 0;
}