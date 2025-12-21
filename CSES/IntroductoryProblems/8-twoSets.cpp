#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;

    ll sum = n * (n + 1) / 2;
    if (sum % 2 == 1)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES" << endl;
        set<int> s1, s2;
        ll num = sum / 2;
        for (int i = n; i >= 1; i--)
        {
            if (i <= num)
            {
                s1.insert(i);
                num -= i;
            }
            else
                s2.insert(i);
        }
        cout << s1.size() << endl;
        for (int x : s1)
            cout << x << " ";
        cout << endl;
        cout << s2.size() << endl;
        for (int x : s2)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}