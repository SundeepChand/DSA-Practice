// https://www.geeksforgeeks.org/find-minimum-number-of-merge-operations-to-make-an-array-palindrome/
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int solveRecursive(vector<int> &nums, int i, int j)
{
    if (j - i <= 1)
        return nums[i] != nums[j];

    int ans = INT_MAX;
    if (nums[i] == nums[j])
        ans = min(ans, solveRecursive(nums, i + 1, j - 1));
    else
    {
        if (nums[i] < nums[j])
        {
            nums[i + 1] += nums[i];
            ans = min(ans, 1 + solveRecursive(nums, i + 1, j));
            nums[i + 1] -= nums[i];
        }
        if (nums[j] < nums[i])
        {
            nums[j - 1] += nums[j];
            ans = min(ans, 1 + solveRecursive(nums, i, j - 1));
            nums[j - 1] -= nums[j];
        }
        // ans = min({ans, solve(nums, i + 1, j), solve(nums, i, j - 1)});
    }
    return ans;
}

int solveIterative(vector<int> nums)
{
    int n = nums.size();
    int i = 0, j = n - 1;
    int res = 0;
    while (i <= j)
    {
        if (nums[i] == nums[j])
            i++, j--;
        else if (nums[i] < nums[j])
            nums[i + 1] += nums[i], i++, res++;
        else
            nums[j - 1] += nums[j], j--, res++;
    }
    return res;
}

int minMerges(vector<int> &nums)
{
    int n = nums.size();

    // return solveRecursive(nums, 0, n - 1);
    return solveIterative(nums);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        cout << minMerges(v) << endl;
    }
    return 0;
}