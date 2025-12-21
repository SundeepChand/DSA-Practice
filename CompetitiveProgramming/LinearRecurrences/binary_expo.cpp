#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;

// TC = O(log b)
int binaryExponent(int a, int b)
{
    int ans = 1, cur = a;
    while (b)
    {
        if (b & 1)
        {
            ans *= cur;
        }
        cur = cur * cur;
        b >>= 1;
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int a, b;
    cin >> a >> b;

    cout << binaryExponent(a, b) << endl;
    return 0;
}