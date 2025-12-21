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
    for (int i = 0; i < m; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int i = n - 1;
    int ans = v[i] - v[0];
    while (i < v.size())
    {
        ans = min(ans, v[i] - v[i - n + 1]);
        i++;
    }
    cout << ans << endl;
    return 0;
}