#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

#define endl "\n"

typedef long long ll;
// #define int ll

/*
2
4
2 4 3 6
2
2 3
3
4 8 9
2
2 5
*/

const int _N = 32001;
bool sieve[_N];
int primes[4000];
int primeSize = 0;

map<int, int> mp;

void initSieve()
{
    memset(sieve, 1, sizeof(sieve));
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i <= _N; i++)
    {
        if (!sieve[i])
            continue;
        primes[primeSize++] = i;
        for (int j = i * i; j <= _N; j += i)
        {
            sieve[j] = 0;
        }
    }
    // cerr << primeSize << endl;
}

void getPrimeFactors(int n)
{
    int i = 0;
    while (n > 1)
    {
        while (i < primeSize and primes[i] <= n and n % primes[i] != 0)
            i++;
        if (i == primeSize or primes[i] > n)
            break;

        while (n % primes[i] == 0)
        {
            n /= primes[i];
        }
        mp[primes[i]]++;
    }
    if (n > 1)
        mp[n]++;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    // auto start = high_resolution_clock::now();

    initSieve();

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        mp.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            getPrimeFactors(v[i]);
        }

        int q;
        cin >> q;
        for (int i = 0; i < q; i++)
        {
            int p;
            cin >> p;
            int val = mp[p];
            int ans = (val * (val - 1)) / 2;
            cout << ans << " ";
        }
        cout << endl;
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<milliseconds>(stop - start);
    // cerr << duration.count() << endl;

    return 0;
}