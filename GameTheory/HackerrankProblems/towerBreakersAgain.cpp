// https://www.hackerrank.com/challenges/tower-breakers-again-1/problem
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    /*
    Solution approach:

    We use a brute force approach here.
    Given a set of stones, we calculate the grundy value for the given state, using Sprague-Grundy
    Theorem. To do this, we find the grundy values for each of the array elements, and take their
    XOR.

    Now when a given element is split, we need to find the grundy values for each of the states, that
    can be reached from the current state. So we find those grundy values and take their Mex.

    We can optimise the code while finding the factors (using Sieve of Eratosthenes), as well as
    memoizing the grundy values for each of the elements.

    However, this solution also works well in the given constraints, hence, its not that optimised.
    */
private:
    bool isPrime(int n)
    {
        int rt = sqrt(n);
        for (int i = 2; i <= rt; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    int mex(unordered_set<int> &u)
    {
        for (int i = 0; true; i++)
        {
            if (u.find(i) == u.end())
                return i;
        }
        return -1;
    }

    int grundy(int n)
    {
        if (n == 1)
            return 0;
        if (isPrime(n))
            return 1;

        unordered_set<int> vals;
        for (int i = 1; i < n; i++)
        {
            if (n % i == 0)
            {
                int ct = n / i;
                if (ct % 2 == 1)
                    vals.insert(grundy(i));
                else
                    vals.insert(0);
            }
        }
        return mex(vals);
    }

public:
    int solve(vector<int> v)
    {
        int n = v.size();

        int xr = 0;
        for (int i = 0; i < n; i++)
        {
            xr ^= grundy(v[i]);
        }
        if (xr == 0)
            return 2;
        return 1;
    }
};

int main()
{
    Solution s;

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