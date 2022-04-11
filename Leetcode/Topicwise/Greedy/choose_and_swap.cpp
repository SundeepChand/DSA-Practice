#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string chooseandswap(string a)
    {
        int n = a.length();

        set<char> s(a.begin(), a.end());

        char first = 0, second = 0;
        for (int i = 0; i < n; i++)
        {
            s.erase(a[i]);
            auto it = s.begin();
            if (s.empty() or *it > a[i])
                continue;
            first = a[i], second = *it;
            break;
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i] == first)
                a[i] = second;
            else if (a[i] == second)
                a[i] = first;
        }
        return a;
    }
};