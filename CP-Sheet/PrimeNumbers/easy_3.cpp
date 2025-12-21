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

    int N = 1e8;
    vector<bool> sieve(N, true);
    sieve[0] = sieve[1] = false;

    for (int i = 2; i < N; i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j < N; j += i)
                sieve[j] = false;
        }
    }

    vector<int> primes;
    for (int i = 0; i < N; i++)
    {
        if (sieve[i])
            primes.push_back(i);
    }
    cerr << primes.size() << endl;

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int k;
        cin >> k;
        cout << primes[k - 1] << endl;
    }
    return 0;
}