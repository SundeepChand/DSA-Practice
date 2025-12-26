// https://leetcode.com/problems/maximum-width-ramp/description/
#include <bits/stdc++.h>
using namespace std;

class SolutionNLogNSorting
{
    // The idea here is that, if we sort the elements based on their values & keep track of their
    // indices, then we already tackle the ordering of array entries. Now we can iterate & keep
    // track of the min index from left & calculate the maximum difference that we can get with
    // the current index.
    // Time complexity: O(n * log n), Space complexity: O(n)
public:
    int maxWidthRamp(vector<int> &nums)
    {
        int n = nums.size();

        vector<vector<int>> vp(n);
        for (int i = 0; i < n; i++)
        {
            vp[i] = {nums[i], i};
        }

        sort(vp.begin(), vp.end());

        int res = 0;
        int minIdx = vp[0][1];
        for (int i = 1; i < n; i++)
        {
            res = max(res, vp[i][1] - minIdx);
            minIdx = min(minIdx, vp[i][1]);
        }
        return res;
    }
};

class SolutionNLogNMonotonicStack
{
    // The idea here is that, from left we start storing only the decreasing elements in a stack
    // (i.e. a decreasing monotonic stack). This is because if we store a bigger element (current value)
    // than top, then st.top is a better choice than the bigger element & it is smaller than current value
    // and is towards left of the array. Now, when we find a bigger element than st.top, we try to find the
    // left-most element in the stack which is less than or equal to the bigger element.
    // Time complexity: O(n * log n), Space complexity: O(n)
public:
    int maxWidthRamp(vector<int> &nums)
    {
        int n = nums.size();

        int res = 0;

        vector<int> st;
        for (int i = 0; i < n; i++)
        {
            if (st.empty() or nums[st.back()] > nums[i])
            {
                st.push_back(i);
            }
            else
            {
                int lb = 0, ub = st.size() - 1;
                int pos = st[ub];
                while (lb <= ub)
                {
                    int mid = lb + (ub - lb) / 2;
                    if (nums[st[mid]] > nums[i])
                    {
                        lb = mid + 1;
                    }
                    else
                    {
                        pos = st[mid];
                        ub = mid - 1;
                    }
                }
                res = max(res, i - pos);
            }
        }
        return res;
    }
};

class SolutionONMonotonicStack
{
    // The idea here is an extension of SolutionNLogNMonotonicStack, where instead of performing binary
    // search every iteration, we build the stack in one pass. And, then iterate backwards and try to
    // pop the stack to find the optimal result.
    // Time complexity: O(n), Space complexity: O(n)
public:
    int maxWidthRamp(vector<int> &nums)
    {
        int n = nums.size();

        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (st.empty() or nums[st.top()] > nums[i])
            {
                st.push(i);
            }
        }

        int res = 0;
        // i >= res is a smaller optimization, than iterating till 0, because we can't find
        // an interval bigger than res, in the range [0...(res-1)]
        for (int i = n - 1; i >= res; i--)
        {
            while (!st.empty() && nums[st.top()] <= nums[i])
            {
                res = max(res, i - st.top());
                st.pop();
            }
        }
        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    SolutionNLogNMonotonicStack s;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        cout << s.maxWidthRamp(v) << endl;
    }
    return 0;
}