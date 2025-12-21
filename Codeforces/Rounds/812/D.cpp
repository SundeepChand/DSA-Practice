#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

int query(int a, int b)
{
    cout << "? " << a << " " << b << endl;
    cout.flush();
    int cmp;
    cin >> cmp;
    return cmp;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int tot = 1 << n;
        set<int> st;
        for (int i = 1; i <= tot; i++)
            st.insert(i);

        while (st.size() > 1)
        {
            auto it = st.begin();
            set<int> temp;
            if (st.size() == 2)
            {
                int a = *it;
                it++;
                int b = *it;
                it++;
                int cmp = query(a, b);
                if (cmp == 1)
                    temp.insert(a);
                else if (cmp == 2)
                    temp.insert(b);
                else if (cmp == -1)
                    return 0;
            }
            while (it != st.end())
            {
                int a = *it;
                it++;
                int b = *it;
                it++;
                int c = *it;
                it++;
                int d = *it;
                it++;
                int cmp = query(a, c);
                if (cmp == -1)
                    return 0;
                else if (cmp == 0)
                {
                    cmp = query(b, d);
                    if (cmp == 1)
                        temp.insert(b);
                    else if (cmp == 2)
                        temp.insert(d);
                }
                else if (cmp == 1)
                {
                    cmp = query(a, d);
                    if (cmp == 1)
                        temp.insert(a);
                    else if (cmp == 2)
                        temp.insert(d);
                }
                else if (cmp == 2)
                {
                    cmp = query(b, c);
                    if (cmp == 1)
                        temp.insert(b);
                    else if (cmp == 2)
                        temp.insert(c);
                }
            }
            st = temp;
        }

        cout << "! " << (*st.begin()) << endl;
        cout.flush();
    }
    return 0;
}