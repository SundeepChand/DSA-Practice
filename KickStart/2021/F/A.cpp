#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    int t;
    cin >> t;

    int temp = t;

    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                v.push_back(i + 1);
        }

        ll ans = 0;
        int j = 0, m = v.size();
        for (int i = 1; i <= n; i++)
        {
            if (j < m)
            {
                if (j == 0)
                    ans += abs(v[j] - i);
                else
                    ans += min(abs(v[j] - i), abs(v[j - 1] - i));
            }
            else
                ans += abs(v[m - 1] - i);

            if (i >= v[j])
                j++;
        }

        cout << "Case #" << (temp - t) << ": " << ans << endl;
    }
    return 0;
}