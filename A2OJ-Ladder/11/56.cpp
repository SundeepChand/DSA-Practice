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

    int s, n;
    cin >> s >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
        v[i].second = -v[i].second;
    }

    sort(v.begin(), v.end());

    int i = 0;
    while (i < n && v[i].first < s)
    {
        s -= v[i].second;
        i++;
    }
    if (i == n)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}