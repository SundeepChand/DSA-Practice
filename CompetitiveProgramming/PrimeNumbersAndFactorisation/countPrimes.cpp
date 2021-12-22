#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        if (n < 2)
            return 0;
        vector<bool> sieve(n, 1);
        sieve[0] = sieve[1] = 0;
        for (int i = 2; i * i < n; i++)
        {
            if (sieve[i] == false)
                continue;
            for (int j = i * i; j < n; j += i)
                sieve[j] = false;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (sieve[i])
                ans++;
        }
        return ans;
    }
};