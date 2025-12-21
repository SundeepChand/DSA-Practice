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

        multiset<int> s;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            s.insert(x);
        }
        set<int> t;
        for (int i = 1; i <= n; i++)
        {
            if (s.find(i) != s.end())
            {
                s.erase(s.find(i));
            }
            else
            {
                t.insert(i);
            }
        }
        int canDo = true, ctr = 0;
        for (auto i : t)
        {
            int front = *(s.begin());
            int x = front - i;
            if (x <= 0 || (front % x != i))
            {
                canDo = false;
                break;
            }
            s.erase(s.begin());
            ctr++;
        }
        if (canDo)
        {
            cout << ctr << endl;
        }
        else
        {
            cout << (-1) << endl;
        }
    }
    return 0;
}