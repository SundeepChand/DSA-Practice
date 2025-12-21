#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;

string sum(string a, string b)
{
    int n = a.length(), m = b.length();
    if (n < m)
    {
        swap(a, b);
        swap(n, m);
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string res = "";
    int i, carry = 0;
    for (i = 0; i < m; i++)
    {
        int d1 = a[i] - '0';
        int d2 = b[i] - '0';
        int sum = d1 + d2 + carry;
        res.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    for (i = m; i < n; i++)
    {
        int d1 = a[i] - '0';
        int sum = d1 + carry;
        res.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    if (carry > 0)
    {
        res.push_back(carry + '0');
    }

    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("in.txt", "r", stdin);
    //     freopen("out.txt", "w", stdout);
    // #endif

    string a, b;
    cin >> a >> b;

    cout << sum(a, b) << endl;
    return 0;
}