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

    int n, m;
    cin >> n >> m;

    vector<int> v(m);
    multiset<int> s1, s2;
    for (int i = 0; i < m; i++)
    {
        cin >> v[i];
        s1.insert(v[i]);
        s2.insert(-v[i]);
    }

    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        int nv1 = 0, nv2 = 0;
        if (s1.size() > 0)
        {
            a += (*s1.begin());
            nv1 = (*s1.begin()) - 1;
            s1.erase(s1.begin());
        }
        if (nv1 > 0)
            s1.insert(nv1);

        if (s2.size() > 0)
        {
            b += (-(*s2.begin()));
            nv2 = (*s2.begin()) + 1;
            s2.erase(s2.begin());
        }
        if (nv2 < 0)
            s2.insert(nv2);
    }
    cout << b << " " << a << endl;
    return 0;
}