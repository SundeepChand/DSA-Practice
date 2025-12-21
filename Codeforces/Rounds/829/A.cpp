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

        string s;
        cin >> s;

        queue<char> q;
        bool hasPrevQ = false, flag = true;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'Q')
            {
                q.push(s[i]);
                hasPrevQ = true;
            }
            else if (hasPrevQ == false)
            {
                flag = false;
                break;
            }
            else
            {
                if (!q.empty())
                    q.pop();
            }
        }
        if (!q.empty())
            flag = false;

        if (flag)
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
}