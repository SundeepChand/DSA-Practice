#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;

int main()
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
        string a, b;
        cin >> a >> b;

        sort(a.begin(), a.end());

        if (b == "abc")
        {
            string s = "", temp = "";
            int i = 0;
            for (i = 0; a[i] == 'a'; i++)
            {
                s += a[i];
            }
            if (s != "")
            {
                while (a[i] == 'b')
                {
                    temp += a[i];
                    i++;
                }
                while (a[i] == 'c')
                {
                    s += a[i];
                    i++;
                }
                s += temp;
                while (i < a.length())
                {
                    s += a[i];
                    i++;
                }
                a = s;
            }
        }
        cout << a << endl;
    }
    return 0;
}