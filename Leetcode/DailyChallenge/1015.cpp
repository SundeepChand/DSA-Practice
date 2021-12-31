#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef long long ll;
    int smallestRepunitDivByK(int k)
    {
        if (k % 2 == 0 || k % 5 == 0)
            return -1;
        ll sum = 1, prev = 1;
        int ans = 1;
        while (ans <= k && sum % k != 0)
        {
            prev = ((10 % k) * prev) % k;
            sum += prev;
            ans++;
        }
        if (sum % k == 0)
            return ans;
        return -1;
    }
};