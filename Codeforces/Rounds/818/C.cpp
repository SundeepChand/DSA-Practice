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

    /*
    Ex 1:
    3 4 1 2
    6 4 2 5

    3 0 1 3

    5 4 1 2
    5 4 1 5
    5 4 2 5

    Ex 2:
    2 4 1
    4 5 3

    2 1 2

    4 4 1
    4 4 3

    Ex 3:
    1 2 3 4 5
    6 5 6 7 6

    5 3 3 3 2

    1 2 3 4 6
    1 2 3 7 6
    1 2 6 7 6
    1 5 6 7 6
    6 5 6 7 6

    Ex 4:
    1 1 1 1
    3 4 5 6

    2 1 1 1
    2 1 1 3
    2 1 4 3
    2 4 4 3
    3 4 4 3
    3 4 4 4
    3 4 5 4

    Ex 5:
    6 3 4
    7 5 5

    6 3 5
    6 5 5
    */

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        bool flag = true, allEq = true;
        int minIdx = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
                allEq = false;
            if (a[i] > b[i])
                flag = false;
            if (b[i] < b[minIdx])
                minIdx = i;
        }
        if (flag)
        {
            int i = minIdx, maxVal = b[minIdx];
            do
            {
                if (a[i] < b[i] and b[i] > maxVal)
                    flag = false;
                maxVal = b[i] + 1;
                // maxVal++;
                i = (i - 1 + n) % n;
            } while (i != minIdx);
        }

        if (flag or allEq)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}