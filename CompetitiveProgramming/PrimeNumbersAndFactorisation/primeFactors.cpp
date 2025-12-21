#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

void factorizeBruteForce(int n)
{
    for (int i = 2; i <= n; i++)
    {
        int ctr = 0;
        while (n % i == 0)
        {
            ctr++;
            n /= i;
        }
        if (ctr > 0)
            cout << i << "^" << ctr << endl;
    }
}

void factorizeNSquared(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        int ctr = 0;
        while (n % i == 0)
        {
            ctr++;
            n /= i;
        }
        if (ctr > 0)
            cout << i << "^" << ctr << endl;
    }
    if (n > 1)
        cout << n << "^1" << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    // factorizeBruteForce(n);
    factorizeNSquared(n);
    return 0;
}