#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n;
    vector<int> v;
    Solution()
    {
        n = 200001;
        v = vector<int>(n, 1);

        v[0] = v[1] = 0;
        // Sieve of eratosthenes
        for (int i = 2; i * i < n; i++)
        {
            if (!v[i])
                continue;
            for (int j = i * i; j < n; j += i)
                v[j] = 0;
        }

        // Find the prefix sum
        for (int i = 1; i < n; i++)
        {
            v[i] += v[i - 1];
        }
    }
    int countPrimes(int L, int R)
    {
        if (L == 0)
            return v[R];
        return (v[R] - v[L - 1]);
    }
};