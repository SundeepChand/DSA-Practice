#include <bits/stdc++.h>
using namespace std;

vector<string> grayCodes(int n)
{
    if (n == 1)
        return {"0", "1"};

    vector<string> sub = grayCodes(n - 1);
    vector<string> res;
    for (int i = 0; i < sub.size(); i++)
    {
        res.push_back("0" + sub[i]);
    }
    for (int i = sub.size() - 1; i >= 0; i--)
    {
        res.push_back("1" + sub[i]);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;

    vector<string> res = grayCodes(n);
    for (auto x : res)
        cout << x << endl;
    return 0;
}