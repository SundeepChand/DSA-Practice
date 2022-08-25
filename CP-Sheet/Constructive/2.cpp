#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

char invert(char digit)
{
    return '9' - digit + '0';
}

// int32_t main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("in.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);
// #endif

//     string s1;
//     cin >> s1;

//     int n = s1.size();
//     string s2 = s1;

//     for (int i = 0; i < n; i++)
//     {
//         if (s1[i] > invert(s1[i]))
//             s1[i] = invert(s1[i]);
//     }

//     reverse(s1.begin(), s1.end());
//     while (!s1.empty() and s1.back() == '0')
//         s1.pop_back();

//     reverse(s1.begin(), s1.end());

//     if (s1.size() > 0)
//         cout << s1;
//     else
//         cout << 9;
//     cout << endl;

//     return 0;
// }

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

    if (s[0] != '9' and s[0] > invert(s[0]))
        s[0] = invert(s[0]);

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] > invert(s[i]))
            s[i] = invert(s[i]);
    }
    cout << s << endl;
    return 0;
}