#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

bool canWin(vector<int> &v, int k)
{
    multiset<int> st(v.begin(), v.end());

    int val = k;

    while (!st.empty())
    {
        auto it2 = st.end();
        it2--;

        st.erase(it2);
        if (*it2 > val)
        {
            continue;
        }

        if (!st.empty())
        {
            auto front = *st.begin();
            st.erase(st.begin());
            st.insert(front + val);
        }
        val--;
    }
    return val == 0;
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

    /*

    - Optimal strategy for Alice: remove the largest value

    */

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (canWin(v, i))
                ans = max(ans, i);
        }
        cout << ans << endl;
    }
    return 0;
}