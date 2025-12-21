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
        string s;
        cin >> s;

        vector<char> v1, v2;

        for (char c : s)
        {
            while (!v1.empty() and v1.back() > c)
            {
                v2.push_back(min(char(v1.back() + 1), '9'));
                v1.pop_back();
            }
            v1.push_back(c);
        }

        sort(v2.begin(), v2.end());

        int i = 0, j = 0;
        int x = v1.size(), y = v2.size();
        while (i < x or j < y)
        {
            if (i >= x)
                cout << v2[j++];
            else if (j >= y)
                cout << v1[i++];
            else if (v1[i] < v2[j])
                cout << v1[i++];
            else
                cout << v2[j++];
        }
        cout << endl;
    }
    return 0;
}