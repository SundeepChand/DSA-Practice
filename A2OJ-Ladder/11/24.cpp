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

    string a, b, c;
    cin >> a >> b >> c;

    map<char, int> m;
    for (auto x : c)
    {
        m[x]++;
    }

    bool flag = true;
    for (auto x : a)
    {
        if (m[x] > 0)
        {
            m[x]--;
            if (m[x] == 0)
            {
                m.erase(x);
            }
        }
        else
        {
            flag = false;
            break;
        }
    }
    for (auto x : b)
    {
        if (m[x] > 0)
        {
            m[x]--;
            if (m[x] == 0)
            {
                m.erase(x);
            }
        }
        else
        {
            flag = false;
            break;
        }
    }
    // cout << flag << ", " << m.size() << endl;
    if (!flag || m.size() > 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
    return 0;
}