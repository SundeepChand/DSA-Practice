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
        // If no color same: 3
        // If 1 pair same: 2
        // If 2 pairs same: 1
        // If 3 colors same: 1
        // If all same: 0

        string a, b;
        cin >> a >> b;

        set<char> st;
        st.insert(a[0]);
        st.insert(a[1]);
        st.insert(b[0]);
        st.insert(b[1]);

        if (st.size() == 4) // no same color
            cout << 3;
        else if (st.size() == 3) // 1 pair same
            cout << 2;
        else if (st.size() == 2) // 2 pairs same or 3 cells same
            cout << 1;
        else if (st.size() == 1) // all same
            cout << 0;
        cout << endl;
    }
    return 0;
}