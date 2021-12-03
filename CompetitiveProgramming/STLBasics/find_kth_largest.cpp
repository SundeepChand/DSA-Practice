#include <bits/stdc++.h>
using namespace std;

// Using Quick select
class Solution
{
public:
    int partition(vector<int> &nums, int lb, int ub)
    {
        // Partitions the array into 3 parts
        int pivot = lb;
        int i = lb, j = lb + 1;
        while (j <= ub)
        {
            if (nums[j] < nums[pivot])
            {
                i++;
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
            j++;
        }
        int temp = nums[i];
        nums[i] = nums[pivot];
        nums[pivot] = temp;
        return i;
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();

        int lb = 0, ub = n - 1;
        while (lb <= ub)
        {
            int pivot_act_idx = partition(nums, lb, ub);
            if (pivot_act_idx == (n - k))
            {
                break;
            }
            else if (pivot_act_idx > (n - k))
            {
                ub = pivot_act_idx - 1;
            }
            else
            {
                lb = pivot_act_idx + 1;
            }
        }
        return nums[n - k];
    }
};