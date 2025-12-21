#include <bits/stdc++.h>
using namespace std;

int getMod(const string &s, int n)
{
    int num = 0;
    for (int i = 0; i < s.size(); i++)
        num = (10 * num + (s[i] - '0')) % n;
    return num;
}

string solve(int n)
{
    queue<string> q;
    q.push("1");

    while (!q.empty())
    {
        string front = q.front();
        q.pop();

        if (getMod(front, n) == 0)
            return front;

        if (front.size() < 40)
        {
            front += '0';
            q.push(front);
            front.pop_back();
            front += '1';
            q.push(front);
        }
    }
    return "-1";
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        cout << solve(n) << endl;
    }
    return 0;
}