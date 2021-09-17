// https://www.hackerrank.com/challenges/tower-breakers-revisited-1/problem
#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000000

class Solution1
{
public:
    // Approach #1: Here we use Sprague-Grundy Theorem to calculate the grundy values
    // for each array element, and then take their XOR to determine the winner of the
    // game.
    int dp[MAX_N + 1];
    vector<int> divisors(int n)
    {
        // Find all the divisors of n
        vector<int> div;
        int rt = sqrt(n);
        for (int i = 1; i <= rt; i++)
        {
            if (n % i == 0)
            {
                div.push_back(i);
                if (i != 1 && i != rt)
                {
                    div.push_back(n / i);
                }
            }
        }
        return div;
    }

    int mex(unordered_set<int> vals)
    {
        for (int i = 0; true; i++)
        {
            if (vals.find(i) == vals.end())
                return i;
        }
        return -1;
    }

    int grundy(int n)
    {
        if (n == 1)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        vector<int> div = divisors(n);
        unordered_set<int> vals;
        for (auto d : div)
        {
            vals.insert(grundy(d));
        }
        return (dp[n] = mex(vals));
    }

    int solve(vector<int> v)
    {
        // Main function.
        memset(dp, -1, sizeof(dp));

        int xr = 0;
        for (int x : v)
        {
            xr ^= grundy(x);
        }

        if (xr == 0)
            return 2;
        return 1;
    }
};

class Solution2
{
public:
    // Approach #2: Here we assume the number of prime factors of a number to be
    // the piles in a nim-game. So basically, in a single move we can remove one
    // or more of the prime factors for a number. Thus, taking the XOR of these
    // count of prime factors we can find the solution. In fact, the grundy function
    // for a single pile is the number of prime factors of the number n.
    vector<int> sieve;
    Solution2()
    {
        // Precompute the prime numbers
        for (int i = 2; i <= MAX_N; i++)
        {
            if (isPrime(i))
                sieve.push_back(i);
        }
    }

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

    int nPrimeFactors(int n)
    {
        int i = 0, ctr = 0;
        while (n > 1)
        {
            while (n % sieve[i] == 0)
            {
                ctr++;
                n /= sieve[i];
            }
            i++;
        }
        return ctr;
    }

    int solve(vector<int> v)
    {
        // Main function.
        int xr = 0;
        for (int x : v)
        {
            xr ^= nPrimeFactors(x);
        }

        if (xr == 0)
            return 2;
        return 1;
    }
};

int main()
{
    // Solution1 s;
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
