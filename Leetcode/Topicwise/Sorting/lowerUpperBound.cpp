#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int lowerBound(vector<int> &v, int start, int end, int target)
{
    int lb = start, ub = end;
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        if (v[mid] < target)
        {
            lb = mid + 1;
        }
        else if (v[mid] >= target)
        {
            ub = mid - 1;
        }
    }
    return lb;
}

int upperBound(vector<int> &v, int start, int end, int target)
{
    int lb = start, ub = end;
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        if (v[mid] <= target)
        {
            lb = mid + 1;
        }
        else if (v[mid] > target)
        {
            ub = mid - 1;
        }
    }
    return lb;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int x, y;
    cin >> x >> y;

    cout << lowerBound(v, 0, n - 1, x) << endl;
    cout << upperBound(v, 0, n - 1, y) << endl;
    return 0;
}