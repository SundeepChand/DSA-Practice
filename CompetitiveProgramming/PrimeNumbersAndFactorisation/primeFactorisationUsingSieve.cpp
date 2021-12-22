#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

vector<int> sieve(100001, 0);
void initSieve()
{
    int N = 100001;
    for (int i = 2; i * i < N; i++)
    {
        if (sieve[i] != 0)
            continue;
        sieve[i] = i;
        for (int j = i * i; j < N; j += i)
        {
            if (sieve[j] == 0)
                sieve[j] = i;
        }
    }
}

void primeFactorisation(int n)
{
    while (n > 1)
    {
        int cur = sieve[n], ctr = 0;
        while (n % cur == 0)
        {
            n /= cur;
            ctr++;
        }
        if (ctr > 0)
            cout << cur << "^" << ctr << endl;
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

    initSieve();
    primeFactorisation(n);
    return 0;
}