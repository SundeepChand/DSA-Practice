#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef long long ll;
    int pairCount(int x, int y)
    {
        int ans = 0;

        ll mult = x * y;
        for (ll i = 1; i * i <= mult; i++)
        {
            if (mult % i == 0)
            {
                ll other = mult / i;
                if (__gcd(i, other) == x)
                {
                    if (i == other)
                        ans++;
                    else
                        ans += 2;
                }
            }
        }
        return ans;
    }
};