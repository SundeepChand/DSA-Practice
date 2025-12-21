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

    string s;
    cin >> s;

    int n = s.size();

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
                sz[i] = (i - st.top() + 1);
                if (st.top() > 0)
                    sz[i] += sz[st.top() - 1];
                st.pop();
            }
        }
    }

    int maxVal = 0, maxCtr = 0;
    for (int x : sz)
    {
        if (x > maxVal)
        {
            maxVal = x;
            maxCtr = 1;
        }
        else if (x == maxVal)
            maxCtr++;
    }
    if (maxVal == 0)
        cout << 0 << " " << 1;
    else
        cout << maxVal << " " << maxCtr;
    cout << endl;

    return 0;
}