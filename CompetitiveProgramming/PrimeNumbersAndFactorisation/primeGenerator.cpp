#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

void init(vector<int> &primes)
{
    int N = 100001;
    vector<bool> sieve(N, 1);
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i * i < N; i++)
    {
        for (int j = i * i; j < N; j += i)
        {
            sieve[j] = 0;
        }
    }
    for (int i = 0; i < N; i++)
        if (sieve[i])
            primes.push_back(i);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    vector<int> primes;
    init(primes);

    while (t--)
    {
        int n, m;
        cin >> m >> n;

        vector<bool> sieve(n - m + 1, 1);
        for (int i : primes)
        {
            if (i * i > n)
                break;
            for (int j = m; j <= n; j++)
            {
                if (j != i && j % i == 0)
                {
                    sieve[j - m] = 0;
                    j += (i - 1);
                }
            }
        }
        for (int i = 0; i < sieve.size(); i++)
        {
            if (i + m != 1 && sieve[i] == 1)
                cout << (i + m) << endl;
        }
        cout << endl;
    }
    return 0;
}