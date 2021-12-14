#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;

int main()
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
        vector<int> v(7);
        for (int i = 0; i < 7; i++)
        {
            cin >> v[i];
        }

        int a = v[0], b = v[1], c = v[6] - v[0] - v[1];
        cout << a << " " << b << " " << c << endl;
    }
    return 0;
}