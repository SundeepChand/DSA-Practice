#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> divisors(int n)
    {
        int diff = INT_MAX;
        int a = 1, b = n;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                int d1 = i, d2 = n / i;
                if (d2 - d1 < diff)
                {
                    diff = d2 - d1;
                    b = d2, a = d1;
                }
            }
        }
        return {a, b};
    }
    vector<int> closestDivisors(int num)
    {
        vector<int> a = divisors(num + 1);
        vector<int> b = divisors(num + 2);
        if (a[1] - a[0] <= b[1] - b[0])
            return a;
        return b;
    }
};