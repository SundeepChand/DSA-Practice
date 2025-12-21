#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int powMod(int a, int b)
{
    int ans = 1, cur = a;
    while (b)
    {
        if (b & 1)
            ans = (ans * cur) % 6;
        b = b >> 1;
        cur = (cur * cur) % 6;
    }
    return ans;
}

int getRemainder(vector<int> &v)
{
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        ans = (ans + powMod(2, i) * v[i]) % 6;
    }
    return ans;
}

vector<int> divideBy6(vector<int> v)
{
    reverse(v.begin(), v.end());
    int n = v.size();

    vector<int> res;
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        cur = 2 * cur + v[i];
        res.push_back(cur / 6);
        cur = cur % 6;
    }
    reverse(res.begin(), res.end());
    while (res.size() && res.back() == 0)
        res.pop_back();
    return res;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        vector<int> res;
        while (v.size() > 0)
        {
            res.push_back(getRemainder(v));
            v = divideBy6(v);
        }
        // cout<<getRemainder(v)<<endl;
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
