#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

// int32_t main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("in.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);
// #endif

//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int a, b, c, d;
//         cin >> a >> b >> c >> d;

//         int g1 = __gcd(a, b), g2 = __gcd(c, d);
//         int a1 = a / g1, b1 = b / g1, c1 = c / g2, d1 = d / g2;

//         // cout << a1 << " " << a << " " << b1 << " " << b << " " << c1 << " " << c << " " << d1 << " " << d << endl;
//         if ((a1 == c1 and b1 == d1) or (a == 0 and c == 0))
//         {
//             cout << 0;
//         }
//         else
//         {
//             int div1 = a * d, div2 = b * c;
//             if ((div1 == 0) or (div2 == 0) or (div1 > div2 and div1 % div2 == 0) or (div2 > div1 and div2 % div1 == 0))
//                 cout << 1;
//             else
//                 cout << 2;
//         }
//         cout << endl;
//     }
//     return 0;
// }
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (((long double)(a) / b) == ((long double)(c) / d))
            cout << 0;
        else if (a == 0 or c == 0 or (a * d) % (b * c) == 0 or (b * c) % (a * d) == 0)
            cout << 1;
        else
            cout << 2;
        cout << endl;
    }

    return 0;
}