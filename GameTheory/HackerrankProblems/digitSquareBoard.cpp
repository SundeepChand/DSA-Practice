// https://www.hackerrank.com/challenges/digits-square-board-1/problem
#include <bits/stdc++.h>
using namespace std;

const int N = 30;

class BruteForceSolution
{
private:
    class Split
    {
    private:
        bool isPrime(int n)
        {
            int rt = sqrt(n);
            for (int i = 2; i <= rt; i++)
                if (n % i == 0)
                    return false;
            return true;
        }

    public:
        int r1, r2, c1, c2;
        Split()
        {
            r1 = r2 = c1 = c2 = 0;
        }
        Split(int r1, int c1, int r2, int c2)
        {
            this->r1 = min(r1, r2);
            this->c1 = min(c1, c2);
            this->r2 = max(r1, r2);
            this->c2 = max(c1, c2);
        }
        int area()
        {
            return abs(r2 - r1 + 1) * abs(c2 - c1 + 1);
        }
        string stringify()
        {
            return to_string(r1) + " " + to_string(r2) + " " + to_string(c1) + " " + to_string(c2);
        }
        bool nonPrimeExist(vector<vector<int>> &v)
        {
            for (int i = r1; i <= r2; i++)
            {
                for (int j = c1; j <= c2; j++)
                {
                    if (!isPrime(v[i][j]))
                        return true;
                }
            }
            return false;
        }
    };

    struct SplitCmp
    {
        bool operator()(Split a, Split b) const
        {
            return (a.stringify() < b.stringify());
        }
    };

    bool firstWin(vector<vector<int>> &v, set<Split, SplitCmp> &u, bool turn)
    {
        bool winner = turn ? false : true;
        for (auto x : u)
        {
            if (x.area() > 1 && x.nonPrimeExist(v))
            {
                // Recursively split that area & find winner
                u.erase(x); // Modifying the data-structure while traversing it may not be safe
                for (int i = x.r1; i < x.r2; i++)
                {
                    Split newSection1 = Split(x.r1, x.c1, i, x.c2);
                    Split newSection2 = Split(i + 1, x.c1, x.r2, x.c2);
                    u.insert(newSection1);
                    u.insert(newSection2);
                    if (turn)
                        winner |= firstWin(v, u, !turn);
                    else
                        winner &= firstWin(v, u, !turn);

                    u.erase(newSection1);
                    u.erase(newSection2);
                }
                u.insert(x);
            }
        }
        return winner;
    }

public:
    string solve(int n, vector<vector<int>> &v)
    {
        set<Split, SplitCmp> u;
        u.insert(Split(0, 0, n - 1, n - 1));

        if (firstWin(v, u, true))
            return "First";
        return "Second";
    }
};

// This is the optimised solution, but still its failing one TC on Hackerrank.
int dp[N][N][N][N];
int dp1[N][N][N][N];
class SolveByFindingGrundyValues
{
public:
    bool isPrime(int n)
    {
        // We are going to deal with nos from 1-9 only. So it is hard-coded here
        if (n == 2 || n == 3 || n == 5 || n == 7)
            return true;
        return false;
    }
    bool hasNonPrimes(const vector<vector<bool>> &v, int r1, int c1, int r2, int c2)
    {
        int &ans = dp1[r1][c1][r2][c2];
        if (ans != -1)
            return ans;
        for (int i = r1; i <= r2; i++)
        {
            for (int j = c1; j <= c2; j++)
            {
                if (!v[i][j])
                    return ans = true;
            }
        }
        return ans = false;
    }
    int mex(const unordered_set<int> &u)
    {
        for (int i = 0; true; i++)
        {
            if (u.find(i) == u.end())
                return i;
        }
        return -1;
    }
    int findGrundyValue(const vector<vector<bool>> &v, int r1, int c1, int r2, int c2)
    {
        int &ans = dp[r1][c1][r2][c2];
        if (ans != -1)
            return ans;

        if ((r1 != r2 || c1 != c2) && hasNonPrimes(v, r1, c1, r2, c2))
        {
            unordered_set<int> vals;
            // Try different splits & take the XOR of the grundy values of the smaller boards
            for (int i = r1; i < r2; i++)
            {
                vals.insert(findGrundyValue(v, r1, c1, i, c2) ^ findGrundyValue(v, i + 1, c1, r2, c2));
            }
            for (int i = c1; i < c2; i++)
            {
                vals.insert(findGrundyValue(v, r1, c1, r2, i) ^ findGrundyValue(v, r1, i + 1, r2, c2));
            }

            return ans = mex(vals);
        }
        return ans = 0;
    }
    string solve(int n, vector<vector<bool>> &v)
    {
        memset(dp, -1, sizeof(dp));
        memset(dp1, -1, sizeof(dp1));
        int grundy = findGrundyValue(v, 0, 0, n - 1, n - 1);
        if (grundy == 0)
            return "Second";
        return "First";
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<bool>> v(n, vector<bool>(n));
        SolveByFindingGrundyValues s;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int x;
                cin >> x;
                v[i][j] = s.isPrime(x);
            }
        }

        // BruteForceSolution s;
        cout << s.solve(n, v) << endl;
    }

    return 0;
}