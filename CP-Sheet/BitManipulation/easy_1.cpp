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

    int n, k;
    cin >> n >> k;

    int left = 0;
    int temp = n;
    while (temp)
    {
        temp >>= 1;
        left++;
    }

    if (k == 1)
        cout << n << endl;
    else
        cout << int(pow(2, left)) - 1 << endl;
    return 0;
}