#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

void printAbsolutePath(stack<string> st)
{
    vector<string> path;
    while (!st.empty())
    {
        path.push_back(st.top());
        st.pop();
    }
    cout << "/";
    for (auto it = path.rbegin(); it != path.rend(); it++)
        cout << *it << "/";
    cout << endl;
}

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

    stack<string> path;

    for (int i = 0; i < n; i++)
    {
        string cmd, param;
        cin >> cmd;

        if (cmd == "pwd")
        {
            printAbsolutePath(path);
        }
        else if (cmd == "cd")
        {
            cin >> param;

            int i = 0;
            if (param[0] == '/')
            {
                path = stack<string>();
                i = 1;
            }
            string cur = "";
            for (; i < param.size(); i++)
            {
                if (param[i] == '/')
                {
                    if (cur == "..")
                        path.pop();
                    else
                        path.push(cur);
                    cur.clear();
                }
                else
                    cur += param[i];
            }
            if (cur == "..")
                path.pop();
            else
                path.push(cur);
        }
    }
    return 0;
}