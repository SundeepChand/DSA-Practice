#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

void printStack(stack<char> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

bool hasDuplicate(string input)
{
    stack<char> s;
    int n = input.length();
    for (int i = 0; i < n; i++)
    {
        if (input[i] == ')')
        {
            int len = 0;
            while (s.top() != '(')
            {
                s.pop();
                len++;
            }
            if (len <= 1)
                return true;
            s.pop();
            s.push('A');
        }
        else
            s.push(input[i]);
        // printStack(s);
    }
    return false;
}

int32_t main()
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
        string input;
        cin >> input;
        cout << hasDuplicate(input) << endl;
    }
    return 0;
}