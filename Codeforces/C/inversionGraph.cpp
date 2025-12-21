#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        int ans = 0;
        stack<pair<int, int>> s;
        for (int i = 0; i < n; i++)
        {
            int lb = v[i], ub = v[i];
            pair<int, int> top = {lb, ub};
            while (!s.empty() && lb < s.top().second)
            {
                top = s.top();
                s.pop();
                lb = min(lb, top.first), ub = max(ub, top.second);
                top = {lb, ub};
            }
            s.push(top);
        }
        cout << s.size() << endl;
    }
    return 0;
}