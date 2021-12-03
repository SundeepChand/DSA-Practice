#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;

int solve(vector<int> &v)
{
    int n = v.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int x : v)
    {
        pq.push(x);
    }
    int ans = 0;
    while (pq.size() > 1)
    {
        int cur_sum = pq.top();
        pq.pop();
        cur_sum += pq.top();
        pq.pop();

        ans += cur_sum;
        pq.push(cur_sum);
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << solve(a) << endl;
    return 0;
}