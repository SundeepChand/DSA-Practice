#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

/*
9
134
56
217
19
2
0
3
21
4
13
8
6
15
29
100
131
18
138
*/

// int v = nFuel == 0 ? 0 : (m / (nFuel + 1));
// if (nFuel == 0)
//     v = 0;
// else if (m % (nFuel + 1) == 0)
//     v = m / (nFuel + 1);
// else
//     v = (m - (m % nFuel)) / nFuel;
// int v = nFuel == 0 ? 0 : (m - (m % nFuel)) / nFuel;
// int nFuel = m / v;
// if (m % v == 0)
//     nFuel--;

pair<int, int> finalFuel(int m, int b, int v)
{
    // int v = round((double)(m) / (nFuel + 1));
    int nFuel = m / v;
    if (m % v == 0)
        nFuel--;

    int rem = m - nFuel * v;
    int totalFuel = b - ((rem * (rem - 1)) / 2) + (1 - (v * (v - 1)) / 2) * nFuel;

    return {nFuel, totalFuel};
}

void getMinTimeAndFuelLinear(int m, int b)
{
    int lb = 1, ub = m + 1;

    int ans = INT_MAX, ansF = 0;
    for (int i = lb; i <= ub; i++)
    {
        auto fFuel = finalFuel(m, b, i);
        if (fFuel.second >= 0)
        {
            if (m + fFuel.first < ans)
                ans = m + fFuel.first, ansF = fFuel.second;
            else if (m + fFuel.first == ans)
                ansF = max(ansF, fFuel.second);
        }
    }
    cout << ans << " " << ansF << endl;
}

// void getMinTimeAndFuel(int m, int b)
// {
//     int lb = 0, ub = m, ans = 0, ansF = 0;

//     while (lb <= ub)
//     {
//         int mid = lb + (ub - lb) / 2; // no of fuel stops

//         auto fFuel = finalFuel(m, b, mid);
//         if (fFuel >= 0)
//         {
//             ub = mid - 1, ans = mid, ansF = fFuel;
//         }
//         else
//             lb = mid + 1;
//     }
//     cout << (m + ans) << " " << ansF << endl;
// }

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
        int m, b;
        cin >> m >> b;

        getMinTimeAndFuelLinear(m, b);
    }
    return 0;
}