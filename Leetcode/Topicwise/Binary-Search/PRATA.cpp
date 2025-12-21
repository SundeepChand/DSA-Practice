#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int getLargestN(int div)
{
    if (div == 0)
        return 0;
    div *= 2;
    int lb = 1, ub = div, ans = lb;
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        if (mid * (mid + 1) > div)
            ub = mid - 1;
        else
            lb = mid + 1, ans = mid;
    }
    return ans;
}

bool canSolve(vector<int> &ranks, int time, int p)
{
    int tot = 0, n = ranks.size();
    for (int i = 0; i < n; i++)
    {
        int div = time / ranks[i];
        tot += getLargestN(div);
    }
    return tot >= p;
}

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
        int p, n;
        cin >> p >> n;

        vector<int> ranks(n);
        for (int i = 0; i < n; i++)
        {
            cin >> ranks[i];
        }

        sort(ranks.begin(), ranks.end());

        int lb = 1, ub = 100000000;
        int ans = ub;
        while (lb <= ub)
        {
            int mid = lb + (ub - lb) / 2;
            if (canSolve(ranks, mid, p))
                ans = mid, ub = mid - 1;
            else
                lb = mid + 1;
        }
        cout << ans << endl;
    }
    return 0;
}