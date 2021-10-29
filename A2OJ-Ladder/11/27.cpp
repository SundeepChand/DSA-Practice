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

    char a[101], b[101];
    cin >> a >> b;

    int val = strcmpi(a, b);
    if (val < 0)
        cout << -1;
    else if (val > 0)
        cout << 1;
    else
        cout << 0;
    cout << endl;
    return 0;
}