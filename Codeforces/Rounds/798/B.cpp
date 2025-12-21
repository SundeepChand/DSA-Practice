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
        int n;
        cin >> n;

        vector<int> v(n);
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            st.insert(v[i]);
        }
        int last = v[n - 1];

        for (int i = 0; i < n; i++)
        {
            auto first = st.begin();
            if (*first == v[i])
            {
                if (st.size() > 1)
                    first++;
            }
            v[i] = *first;
            st.erase(first);
        }
        if (n > 1)
        {
            if (v[n - 1] == last)
                swap(v[n - 1], v[n - 2]);
            for (int x : v)
                cout << x << " ";
        }
        else
            cout << (-1);
        cout << endl;
    }
    return 0;
}