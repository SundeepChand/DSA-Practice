#include <bits/stdc++.h>
using namespace std;

class Solution1
{
    // TC = O(n), SC = O(n), using hash-table
public:
    vector<int> singleNumber(vector<int> nums)
    {
        unordered_set<int> u;
        for (int x : nums)
        {
            if (u.find(x) != u.end())
            {
                u.erase(x);
            }
            else
            {
                u.insert(x);
            }
        }
        vector<int> ans = vector<int>(u.begin(), u.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};

class Solution
{
    // TC = O(n), SC = O(1)
public:
    vector<int> singleNumber(vector<int> nums)
    {
        int xr = 0;
        for (int x : nums)
        {
            xr ^= x;
        }
        int temp = xr, mask = 1;
        while (temp)
        {
            temp >>= 1;
            mask <<= 1;
        }
        mask >>= 1;
        int n1 = 0;
        for (int x : nums)
        {
            if (x & mask)
            {
                n1 ^= x;
            }
        }
        int n2 = xr ^ n1;
        vector<int> v = {n1, n2};
        sort(v.begin(), v.end());
        return v;
    }
};