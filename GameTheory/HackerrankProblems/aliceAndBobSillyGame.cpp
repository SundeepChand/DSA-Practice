// https://www.hackerrank.com/challenges/alice-and-bobs-silly-game/problem
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    int rt = sqrt(n);
    for (int i = 2; i <= rt; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

// int primes(int n)
// {
//     int ctr = 0;
//     for (int i = 2; i <= n; i++)
//     {
//         if (isPrime(i))
//             ctr++;
//     }
//     return ctr;
// }

int main()
{
    // Precompute the prefix-sum for the sieve-of-eratosthenes
    vector<int> v(100001);
    v[1] = 0;
    for (int i = 2; i <= 100001; i++)
    {
        v[i] = v[i - 1];
        if (isPrime(i))
        {
            v[i]++;
        }
    }

    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;

        int p = v[n];

        if (p % 2 == 0)
            cout<<"Bob";
        else
            cout<<"Alice";
        cout<<endl;
    }
    return 0;
}