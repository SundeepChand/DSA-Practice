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

    int t;
    cin >> t;

    int ctr = 0;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if ((a + b + c) >= 2)
            ctr++;
    }
    cout << ctr << endl;
    return 0;
}