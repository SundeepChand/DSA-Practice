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
    if (n % 2 == 1)
    {
        cout << "No" << endl;
        return 0;
    }

    stack<char> st;
    for (char c : s)
    {
        if (!st.empty() and st.top() == c)
            st.pop();
        else
            st.push(c);
    }
    if (st.empty())
        cout << "Yes";
    else
        cout << "No";
    cout << endl;
    return 0;
}