#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll solve(int n)
{
    ll ans = 0, s = 1;
    for (int i = 0; i < 5; i++)
    {
        s *= (n - i);
    }
    s /= 120;
    ans += s;
    s *= (n - 5);
    s /= 6;
    ans += s;
    s *= (n - 6);
    s /= 7;
    ans += s;
    return ans;
}