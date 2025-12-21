#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    int temp = t;
    while (t--)
    {
        int d, n, k;
        cin >> d >> n >> k;

        map<int, vector<int>> m1, m2;
        for (int i = 0; i < n; i++)
        {
            int h, s, e;
            cin >> h >> s >> e;
            m1[s].push_back(h);
            m2[e].push_back(h);
        }

        int ans = 0;
        multiset<int> s;
        for (int i = 1; i <= d; i++)
        {
            for (auto x : m1[i])
                s.insert(x);
            for (auto x : m2[i])
            {
                if (s.find(x) != s.end())
                    s.erase(s.find(x));
            }

            int cur = 0, j = 0;
            for (auto it = s.rbegin(); it != s.rend() && j < k; it++, j++)
            {
                cur += *it;
            }
            if (cur > ans)
                ans = cur;
        }

        cout << "Case #" << (temp - t) << ": " << ans << endl;
    }
    return 0;
}