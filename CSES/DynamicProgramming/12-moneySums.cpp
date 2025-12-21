#include <bits/stdc++.h>
using namespace std;

set<int> solve(vector<int> &v, int n)
{
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        set<int> ns = s;
        for (auto it = s.begin(); it != s.end(); it++)
        {
            ns.insert(*it + v[i]);
        }
        ns.insert(v[i]);
        s = ns;
    }
    return s;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    set<int> vals = solve(v, n);
    cout << vals.size() << endl;
    for (auto x : vals)
        cout << x << " ";
    cout << endl;
    return 0;
}