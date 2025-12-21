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
        int n;
        cin >> n;

        if (n % 2 == 0)
        {
            cout << (n - 3) << " 2 1" << endl;
        }
        else if (n % 2 == 1)
        {
            int k = (n - 1) / 2;
            if (k % 2 == 1)
                cout << (k + 2) << " " << (k - 2) << " " << 1 << endl;
            else
                cout << (k + 1) << " " << (k - 1) << " " << 1 << endl;
        }
    }
    return 0;
}