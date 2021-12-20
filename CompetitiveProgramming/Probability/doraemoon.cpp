// https://codeforces.com/problemset/problem/476/B
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

vector<double> ss;
void sample_space(string s, int i, double dist)
{
    if (i >= s.length())
    {
        ss.push_back(dist);
        return;
    }
    if (s[i] == '+')
        sample_space(s, i + 1, dist + 1);
    else if (s[i] == '-')
        sample_space(s, i + 1, dist - 1);
    else
    {
        sample_space(s, i + 1, dist + 1);
        sample_space(s, i + 1, dist - 1);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    string s1, s2;
    cin >> s1 >> s2;

    double d1 = 0;
    for (char c : s1)
    {
        if (c == '+')
            d1 += 1;
        else
            d1 -= 1;
    }

    sample_space(s2, 0, 0.0);
    int ctr = 0;
    for (double x : ss)
    {
        if (x == d1)
            ctr++;
    }
    long double ans = (long double)(ctr) / ss.size();
    cout.setf(ios::fixed);
    cout << setprecision(12) << ans << endl;
    return 0;
}