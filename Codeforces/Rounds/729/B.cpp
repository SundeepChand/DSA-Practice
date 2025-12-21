#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;

bool type2(int n, int a, int b)
{
    if (a == 1)
    {
        return ((n - 1) % b == 0);
    }
    while (n % a == 0)
    {
        n /= a;
    }
    return ((n - 1) % b) == 0;
}

bool type3(int n, int a, int b)
{
    if (a == 1)
    {
        return ((n - 1) % b == 0);
    }
    ll cur = 1;
    while (cur < n)
    {
        if ((n - cur) % b == 0)
            return true;
        cur = cur * a;
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;

        if (type3(n, a, b))
        {
            cout << "Yes" << endl;
        }
        else if (type2(n, a, b))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}