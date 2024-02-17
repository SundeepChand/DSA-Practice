#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

bool canMakeSmaller(vector<int> &s, vector<int> &t)
{
    map<char, int> mp1, mp2;
    for (int i = 0; i < 26; i++)
    {
        if (s[i] != 0)
            mp1[i + 'a'] = s[i];
        if (t[i] != 0)
            mp2[i + 'a'] = t[i];
    }

    auto it1 = mp1.begin();
    auto it2 = mp2.rbegin();
    while (it1 != mp1.end() and it2 != mp2.rend())
    {
        if (it1->first < it2->first)
        {
            return true;
        }
        else if (it1->first > it2->first)
            return false;
        else
        {
            if (it1->second == it2->second)
                it1++, it2++;
            else if (it1->second < it2->second)
                it1++;
            else
                it2++;
        }
    }
    if (it1 == mp1.end())
        return it2 != mp2.rend();
    return false;
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
        int q;
        cin >> q;

        vector<int> s(26, 0), t(26, 0);
        s[0] = t[0] = 1;
        for (int i = 0; i < q; i++)
        {
            int d;
            cin >> d;

            int x;
            cin >> x;

            string cur;
            cin >> cur;

            vector<int> &v = (d == 1) ? s : t;
            for (char c : cur)
                v[c - 'a'] += x;

            if (canMakeSmaller(s, t))
                cout << "YES";
            else
                cout << "NO";
            cout << endl;
        }
    }
    return 0;
}