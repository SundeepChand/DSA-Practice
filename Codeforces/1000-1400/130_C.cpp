// https://codeforces.com/problemset/problem/1697/C
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

vector<int> getNextCharPos(const string &s, char c)
{
    int n = s.size();
    vector<int> res(n, -1);

    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (s[i] == c and !st.empty())
        {
            res[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return res;
}

bool canMakeEqual(string &s, const string &t)
{
    int n = s.size();

    vector<int> nextB = getNextCharPos(s, 'b');
    vector<int> nextC = getNextCharPos(s, 'c');

    for (int x : nextB)
        cerr << x << " ";
    cerr << endl;

    int offset = 0;
    char prev = s[0];

    for (int i = 0; i < n; i++)
    {
        // if (s[i] != prev)
        //     offset = next[i];
        cerr << "DEB: " << s << " " << t << " " << i << " " << endl;

        prev = s[i];
        if (s[i] == t[i])
            continue;

        if ((s[i] == 'a' and t[i] == 'b') or (s[i] == 'b' and t[i] == 'c'))
        {
            // if (offset == 0 or offset >= n or s[offset] != t[i])
            //     return false;

            // swap(s[i], s[offset]);
            // offset++;
            int j = i + 1;
            while (j < n and s[j] != (s[i] == 'a' ? 'b' : 'c'))
                j++;

            if (j >= n)
                return false;
            swap(s[i], s[j]);
        }
        else
            return false;
    }
    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    /*
        0 1 2 3 4 5
    t = b b a a c b

    s = a b b a b c
        1 0 0 4 5 0

        if (s[i] != prev)
            offset = 0;

        if (s[i] == t[i])
            continue;

        if (s[i] == 'a' and t[i] == 'b' or s[i] =='b' and t[i] == 'c')
        {
            if (next[i] == 0)
                return false;

            swap(s[i], s[next[i]]);
            offset++;
        }
        else
            return false;
    */

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s, t;
        cin >> s;
        cin >> t;
        cerr << s << " " << t << endl;

        if (canMakeEqual(s, t))
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}