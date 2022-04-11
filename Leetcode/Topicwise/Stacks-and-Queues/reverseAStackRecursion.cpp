#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

template <class T>
class Stack
{
private:
    stack<T> s;

public:
    void push(T val)
    {
        s.push(val);
    }

    void printStack()
    {
        stack<int> temp = s;
        while (!temp.empty())
        {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }

    void insertAtBottom(T x)
    {
        if (s.empty())
            s.push(x);
        else
        {
            T cur = s.top();
            s.pop();
            insertAtBottom(x);
            s.push(cur);
        }
    }

    void reverseStack()
    {
        if (!s.empty())
        {
            T cur = s.top();
            s.pop();
            reverseStack();
            insertAtBottom(cur);
        }
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    Stack<int> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.push(x);
    }
    s.printStack();

    s.reverseStack();

    s.printStack();
    return 0;
}