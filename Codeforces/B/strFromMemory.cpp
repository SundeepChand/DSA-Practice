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
        string s;
        cin >> s;

        int n = s.size();

        int days = 0;

        for (int i = 0; i < n; i++)
        {
            int newChars = 0;
            set<char> st;
            days++;
            while (i < n and newChars <= 3)
            {
                if (st.find(s[i]) == st.end())
                {
                    if (newChars < 3)
                    {
                        newChars++;
                        st.insert(s[i]);
                    }
                    else
                        break;
                }
                i++;
            }
            i--;
        }
        cout << days << endl;
    }
    return 0;
}