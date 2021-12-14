#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;

int main()
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
        int n, k;
        cin >> n >> k;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        sort(v.begin(), v.end());
        int ans = 0;
        for (int i = 0; i < (n - 2 * k); i++)
        {
            ans += v[i];
        }
        map<int, int> f;
        for (int i = (n - 2 * k); i < n; i++)
        {
            f[v[i]]++;
        }
        priority_queue<int> pq;
        for (auto x : f)
        {
            pq.push(x.second);
        }
        while (pq.size() > 2)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            pq.push(a - b);
        }
        int ctr = 0;
        if (pq.size() > 0)
            ctr = pq.top();
        ans += ctr / 2;

        cout << ans << endl;
    }
    return 0;
}