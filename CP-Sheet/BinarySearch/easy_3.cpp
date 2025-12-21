#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;

    n--, k--;

    int sum = (k * (k + 1)) / 2;

    if (n == 0)
        cout << 0;
    else if (sum < n)
        cout << -1;
    else if (k >= n)
        cout << 1;
    else
    {
        // Find the smallest P for which
        //    n - S(P) - 1 <= k - P - 1
        // => S(P) >= (n - k) + P
        // Solution reference: https://github.com/mostafa-saad/ArabicCompetitiveProgramming/blob/master/13%20Programming%20Practise%20-%20CodeForces%20-%20Div2%20-%20B/CodeForces%20-%20Div2%20-%20176%20-%20B%20-%20Pipeline.cpp

        int lb = 1, ub = k;
        int ans = ub;
        while (lb <= ub)
        {
            int mid = lb + (ub - lb) / 2;
            int pPrev = k - mid;
            int sumOfLastMid = (k * (k + 1)) / 2 - (pPrev * (pPrev + 1)) / 2;

            if (sumOfLastMid >= n - k + mid)
            {
                ans = mid;
                ub = mid - 1;
            }
            else
            {
                lb = mid + 1;
            }
        }
        cout << (ans + 1);
    }
    cout << endl;
    return 0;
}