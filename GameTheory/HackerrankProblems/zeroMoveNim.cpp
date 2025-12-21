// https://www.hackerrank.com/challenges/zero-move-nim/problem
#include <bits/stdc++.h>
using namespace std;

class Solution1
{
    // This is the brute force approach, where we try to find the grundy values recursively
private:
    unordered_map<int, int> dp;
    int mex(unordered_set<int> vals)
    {
        for (int i = 0; true; i++)
            if (vals.find(i) == vals.end())
                return i;
        return -1;
    }

    int grundy(int n)
    {
        if (n == 0)
            return 0;

        if (dp.find(n) != dp.end())
            return dp[n];

        unordered_set<int> vals;
        vals.insert(n);
        for (int i = 0; i < n; i++)
        {
            vals.insert(grundy(i));
        }
        return (dp[n] = mex(vals));
    }

public:
    char solve(const vector<int> &v)
    {
        int xr = 0;
        for (int i = 0; i < v.size(); i++)
        {
            xr ^= grundy(v[i]);
        }
        if (xr == 0)
            return 'L';
        return 'W';
    }

    void printGrundyValues(int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << ": " << grundy(i) << endl;
        }
    }
};

class Solution2
{
    // On printing the grundy values for some elements, we observe the pattern below.
    // Thus we find grundy values in O(1) time
private:
    int grundy(int n)
    {
        if (n == 0)
            return 0;
        if (n % 2 == 0)
            return n - 1;
        return n + 1;
    }

public:
    char solve(const vector<int> &v)
    {
        int xr = 0;
        for (int i = 0; i < v.size(); i++)
        {
            xr ^= grundy(v[i]);
        }
        if (xr == 0)
            return 'L';
        return 'W';
    }
};

int main()
{
    Solution2 s;
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

        cout << s.solve(v) << endl;
    }
    return 0;
}