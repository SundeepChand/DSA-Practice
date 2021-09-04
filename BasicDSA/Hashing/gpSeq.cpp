#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> v, int r)
{
    // Time complexity = O(n * log n)
    unordered_map<int, vector<int>> u;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        u[v[i]].push_back(i);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a = v[i];
        int b = a * r, c = a * r * r;
        for (int j = upper_bound(u[b].begin(), u[b].end(), i) - u[b].begin(); j < u[b].size(); j++)
        {
            int k = u[c].end() - upper_bound(u[c].begin(), u[c].end(), j);
            ans += k;
        }
    }
    return ans;
}

int solveLinear(vector<int> v, int r)
{
    unordered_map<int, int> left, right;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        right[v[i]]++;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        right[v[i]]--;

        if (v[i] % r == 0)
        {
            int a = v[i] / r, b = v[i] * r;
            ans += left[a] * right[b];
        }

        left[v[i]]++;
    }
    return ans;
}

int main()
{
    // vector<int> v1 = {1,1,2,2,4};
    // int r1 = 2;
    // int r1 = 3;

    // vector<int> v1 = {4,2,10,4,4,8,20,40};
    // int r1 = 2;

    vector<int> v1 = {1,1,1,1,1};
    int r1 = 1;

    cout<<solveLinear(v1, r1)<<endl;
    return 0;
}