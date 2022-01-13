#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size(), prev = INT_MIN;
        int i = 0, j = 0;
        while (j < n)
        {
            if (nums[j] != prev)
            {
                nums[i] = nums[j];
                prev = nums[i];
                i++;
            }
            j++;
        }
        return i;
    }
};