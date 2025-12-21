#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int> &A, int K)
    {
        unordered_map<int, int> m;
        int ctr = 0;
        long long cs = 0;

        for (int i = 0; i < A.size(); i++)
        {
            cs += A[i];
            int mod = cs % K;
            if (mod < 0)
                mod += K;
            if (mod == 0)
                ctr++;
            ctr += m[mod];
            m[mod]++;
        }
        return ctr;
    }
};

class Solution1
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        vector<int> freq(k, 0);

        int n = nums.size();
        int rem = nums[0] % k;
        if (rem < 0)
            rem = k + rem;
        freq[rem]++;
        for (int i = 1; i < n; i++)
        {
            int sum = nums[i - 1] + nums[i];
            rem = sum % k;
            if (rem < 0)
                rem = k + rem;
            freq[rem]++;
            nums[i] += nums[i - 1];
        }

        int ans = freq[0];
        for (int i = 0; i < k; i++)
        {
            ans += ((freq[i] - 1) * freq[i]) / 2;
        }
        return ans;
    }
};