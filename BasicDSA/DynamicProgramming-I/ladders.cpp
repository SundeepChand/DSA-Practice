#include <bits/stdc++.h>
using namespace std;

int solveRecursive(int n, int k)
{
    if (n == 0)
        return 1;
    
    int ans = 0;
    for (int i = 1; (n - i) >= 0 && i <= k; i++)
    {
        ans += solveRecursive(n - i, k);
    }
    return ans;
}

int solveBottomUpONK(int n, int k)
{
    deque<int> dp;
    dp.push_back(1);
    
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (auto it = dp.begin(); it != dp.end(); it++)
        {
            sum += *it;
        }
        dp.push_back(sum);
        if (dp.size() > k)
            dp.pop_front();
    }

    // Show the dp
    cout<<"DP: ";
    for (auto x: dp)
    {
        cout<<x<<" ";
    }
    cout<<endl;

    return dp.back();
}

int solveBottomUpON(int n, int k)
{
    deque<int> dp;
    dp.push_back(1);
    int sum = 0;
    if (n < k)
    {
        k = n;
    }
    for (int i = 1; i <= k; i++)
    {
        sum += dp.back();
        dp.push_back(sum);
    }
    
    for (int i = k + 1; i <= n; i++)
    {
        sum += dp.back();
        sum -= dp.front();
        dp.push_back(sum);
        dp.pop_front();
    }

    // Show the dp
    cout<<"DP: ";
    for (auto x: dp)
    {
        cout<<x<<" ";
    }
    cout<<endl;

    return dp.back();
}

int main()
{
    int n = 3, k = 3;

    cout<<solveRecursive(n, k)<<endl;
    cout<<solveBottomUpONK(n, k)<<endl;
    cout<<solveBottomUpON(n, k)<<endl;

    return 0;
}