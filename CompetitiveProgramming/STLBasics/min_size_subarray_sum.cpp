#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();

        int a = 0, b = 0;
        int cur_sum = nums[b], ans = n + 1;
        while (b < n)
        {
            if (cur_sum >= target)
            {
                ans = min(ans, (b - a + 1));
                cur_sum -= nums[a];
                a++;
                if (b < a)
                {
                    b = a;
                }
            }
            else
            {
                b++;
                if (b < n)
                    cur_sum += nums[b];
            }
        }
        if (ans == (n + 1))
            return 0;
        return ans;
    }
};