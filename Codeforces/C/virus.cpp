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

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> v(m);
        for (int i = 0; i < m; i++)
        {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        priority_queue<int> pq;
        pq.push(n - v[m - 1] + v[0] - 1);
        for (int i = 1; i < m; i++)
        {
            pq.push(v[i] - v[i - 1] - 1);
        }

        int nUnInfected = 0, days = 0;
        while (!pq.empty())
        {
            auto front = pq.top();
            pq.pop();

            front -= 2 * days;
            if (front > 1)
                front--;
            days += 2;
            if (front > 0)
                nUnInfected += front;
        }
        cout << (n - nUnInfected) << endl;
    }
    return 0;
}