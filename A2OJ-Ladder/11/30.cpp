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

    int n;
    cin >> n;

    vector<int> v(n);
    unordered_map<int, int> u;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        u[v[i]] = i + 1;
    }

    ll a = 0, b = 0;
    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;

        a = a + ll(u[x]);
        b = b + (n - ll(u[x]) + 1);
    }
    cout << a << " " << b << endl;
    return 0;
}