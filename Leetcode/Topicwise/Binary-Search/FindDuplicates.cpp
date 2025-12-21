#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    vector<int> duplicates(int arr[], int n)
    {
        set<int> ans;
        for (int i = 0; i < n; i++)
        {
            int idx = arr[i];
            if (idx < 0)
                idx = idx * (-1) - 1;
            if (arr[idx] < 0)
            {
                int val = arr[i];
                if (val < 0)
                    val = val * (-1) - 1;
                ans.insert(val);
            }
            else
                arr[idx] = (arr[idx] + 1) * (-1);
        }
        if (ans.size() == 0)
            ans.insert(-1);
        return vector<int>(ans.begin(), ans.end());
    }
};

class Solution1
{
public:
    vector<int> duplicates(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
            arr[arr[i] % n] += n;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if ((arr[i] / n) > 1)
                ans.push_back(i);
        }
        sort(ans.begin(), ans.end());
        if (ans.size() == 0)
            ans.push_back(-1);
        return ans;
    }
};

int main()
{
    return 0;
}