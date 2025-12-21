#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;

string solve(int a, int b, int c)
{
    if (c % 2 == 0)
    {
        if (abs(a) > abs(b))
            return ">";
        else if (abs(a) < abs(b))
            return "<";
        else
            return "=";
    }
    else
    {
        if ((a >= 0 && b >= 0) || (a < 0 && b < 0))
        {
            if (a > b)
                return ">";
            else if (a < b)
                return "<";
            else
                return "=";
        }
        else if (a < 0 && b >= 0)
        {
            return "<";
        }
        else if (a >= 0 && b < 0)
        {
            return ">";
        }
    }
    return "";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c) << endl;
    return 0;
}