#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> prev(n, 0);
    stack<int> s; // Maintain an increasing monotonic stack
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && v[s.top()] >= v[i])
        {
            s.pop();
        }
        if (!s.empty())
        {
            prev[i] = s.top() + 1;
        }
        s.push(i);
    }

    // Print the output
    for (int x : prev)
        cout << x << " ";
    cout << endl;
    return 0;
}