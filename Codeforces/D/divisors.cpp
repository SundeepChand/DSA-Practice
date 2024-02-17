// https://codeforces.com/contest/1366/problem/D
#include <bits/stdc++.h>
using namespace std;

unordered_map<int, bool> primes;
bool isPrime(int x)
{
    if (primes.find(x) != primes.end())
        return primes[x];
    int rt = sqrt(x);
    for (int i = 2; i <= rt; i++)
    {
        if (x % i == 0)
        {
            return primes[x] = false;
        }
    }
    return primes[x] = true;
}

pair<int, int> solve(int x)
{
    int rt = sqrt(x);
    int ctr = 0;
    int a = -1, b = -1;
    for (int i = 2; i <= rt; i++)
    {
        if ((x % i == 0))
        {
            if (isPrime(i))
            {
                if (ctr == 0)
                    a = i;
                else
                    b = i;
                ctr++;
            }
            if ((x / i) != i && isPrime(x / i))
            {
                if (ctr == 0)
                    a = (x / i);
                else
                    b = (x / i);
                ctr++;
            }
            if (ctr >= 2)
                break;
        }
    }
    if (ctr <= 1)
        return {-1, -1};
    return {a, b};
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> d1, d2;
    for (auto x : a)
    {
        pair<int, int> p = solve(x);
        d1.push_back(p.first);
        d2.push_back(p.second);
    }

    for (auto x : d1)
    {
        cout << x << " ";
    }
    cout << endl;
    for (auto x : d2)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}