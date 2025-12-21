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
        int x;
        cin >> x;

        string s;
        cin >> s;

        int n = s.size();

        int ans = n;

        vector<int> sz(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                if (!st.empty())
                {
                    sz[i] = 1;
                    if (st.top() > 0 and sz[st.top() - 1] > 0)
                        sz[i]++;
                    // sz[i] += sz[st.top() - 1];
                    st.pop();
                }
                ans -= sz[i];
            }
        }
        cout << ans << endl;
    }

    return 0;
}