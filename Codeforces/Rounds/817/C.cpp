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

        // Maintain a set of words for each person, and assign score based on the condition

        set<string> s1, s2, s3;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            s1.insert(s);
        }

        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            s2.insert(s);
        }

        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            s3.insert(s);
        }

        int a = 0, b = 0, c = 0;
        for (auto x : s1)
        {
            if (s2.find(x) == s2.end() and s3.find(x) == s3.end())
                a += 3;
            else if (s2.find(x) == s2.end() or s3.find(x) == s3.end())
                a += 1;
        }

        for (auto x : s2)
        {
            if (s1.find(x) == s1.end() and s3.find(x) == s3.end())
                b += 3;
            else if (s1.find(x) == s1.end() or s3.find(x) == s3.end())
                b += 1;
        }

        for (auto x : s3)
        {
            if (s1.find(x) == s1.end() and s2.find(x) == s2.end())
                c += 3;
            else if (s1.find(x) == s1.end() or s2.find(x) == s2.end())
                c += 1;
        }

        cout << a << " " << b << " " << c << endl;
    }
    return 0;
}