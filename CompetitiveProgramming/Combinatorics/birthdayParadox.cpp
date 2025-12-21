#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    long double p = 1, n = 365, d = 365;
    int people = 0;
    while (p >= 0.3)
    {
        people++;
        p *= (n / d);
        n--;
        cout << "People = " << people << ", Proba = " << p << endl;
    }
    cout << p << endl;
    cout << people << endl;
    return 0;
}