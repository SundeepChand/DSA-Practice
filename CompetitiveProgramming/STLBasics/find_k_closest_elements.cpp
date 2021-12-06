#include <bits/stdc++.h>
using namespace std;

class Solution1
{
    // O(n * log n) solution
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int a : arr)
        {
            pq.push({abs(a - x), a});
        }
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            pair<int, int> top = pq.top();
            pq.pop();
            ans.push_back(top.second);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

class Solution
{
    // O(n) solution
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int n = arr.size();
        int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        if (idx > 0 && idx < n && abs(arr[idx] - x) >= abs(arr[idx - 1] - x))
        {
            idx--;
        }
        if (idx >= n)
        {
            idx--;
        }

        vector<int> ans;
        ans.push_back(arr[idx]);
        int i = idx - 1, j = idx + 1, l = 1;
        while (l < k)
        {
            if (i < 0)
            {
                ans.push_back(arr[j]);
                j++;
            }
            else if (j >= n)
            {
                ans.push_back(arr[i]);
                i--;
            }
            else if (abs(arr[i] - x) <= abs(arr[j] - x))
            {
                ans.push_back(arr[i]);
                i--;
            }
            else
            {
                ans.push_back(arr[j]);
                j++;
            }
            l++;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};