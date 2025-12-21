#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

ll pow10(int n)
{
    ll res = 1;
    for (int i = 0; i < n; i++)
    {
        res *= 10;
    }
    return res;
}

int main()
{
    vector<ll> b(17);

    b[0] = 9;
    for (int i = 1; i < b.size(); i++)
    {
        b[i] = b[i - 1] + ll(9) * pow10(i) * (i + 1);
    }

    int q;
    cin >> q;
    while (q--)
    {
        ll k;
        cin >> k;

        // Find the largest no in the bucket, less than k
        int idx = -1;
        for (int i = 0; i < b.size(); i++)
        {
            if (b[i] <= k)
            {
                idx = i;
            }
        }

        if (idx == -1)
        {
            cout << k;
        }
        else if (b[idx] == k)
        {
            cout << 9;
        }
        else
        {
            // idx + 2 gives the no of digits in the number
            int digits = idx + 2;
            ll offset = k - b[idx];
            // ll num = ceil(double(offset) / double(digits));
            ll num = (offset - 1) / digits;

            ll prev_nine = 0;
            int i = digits;
            while (i > 1)
            {
                prev_nine = 10 * prev_nine + 9;
                i--;
            }
            num += prev_nine + 1;

            ll s = b[idx] + 1 + ((offset - 1) / digits) * digits; // Start index of the number

            string ns = to_string(num);
            cout << ns[k - s];
        }
        cout << endl;
    }
    return 0;
}

// 738946392488756803  Expected o/p = 1;

// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// int main()
// {
//     ll t;
//     cin >> t;

//     while (t--)
//     {
//         ll k;
//         cin >> k;

//         ll l = 1, d = 0, m = 9;
//         while (d + l * m < k)
//         {
//             d += l * m;
//             l++;
//             m *= 10;
//         }
//         k -= d;

//         ll add = (k - 1) / l;
//         ll number = pow(10, l - 1);
//         number += add;
//         k -= add * l;
//         string num = to_string(number);
//         cout << num[k - 1] << endl;
//     }
//     return 0;
// }