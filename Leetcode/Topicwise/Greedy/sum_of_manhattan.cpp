#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

void getSumFromVec(const vector<int> &v, int &sum)
{
    int n = v.size();
    int curSum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += i * v[i] - curSum;
        curSum += v[i];
    }
}

int getSumOfAllDist(vector<pair<int, int>> &points)
{
    int n = points.size();
    int sum = 0;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++)
    {
        x[i] = points[i].first, y[i] = points[i].second;
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    // Calculate ans for x
    getSumFromVec(x, sum);
    getSumFromVec(y, sum);
    return sum;
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

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].first >> points[i].second;
    }

    cout << getSumOfAllDist(points) << endl;

    return 0;
}