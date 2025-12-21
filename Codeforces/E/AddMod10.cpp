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

    map<int, int> sumVal;
    sumVal[1] = 3;
    sumVal[2] = 2;
    sumVal[3] = 11;
    sumVal[4] = 0;
    sumVal[5] = 5;
    sumVal[6] = 8;
    sumVal[7] = 7;
    sumVal[8] = 16;
    sumVal[9] = 25;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        bool multipleOf5 = false;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] % 10 == 5)
                v[i] += sumVal[5], multipleOf5 = true;
            else if (v[i] % 10 == 0)
                multipleOf5 = true;
            else
                v[i] += sumVal[v[i] % 10];
        }

        bool poss = true;
        if (multipleOf5)
        {
            for (int i = 1; i < n; i++)
            {
                if (v[i] != v[i - 1])
                {
                    poss = false;
                    break;
                }
            }
        }
        else
        {
            for (int i = 1; i < n; i++)
            {
                if ((v[0] - v[i]) % 20 != 0)
                {
                    poss = false;
                    break;
                }
            }
        }
        if (poss)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}
