#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        unordered_set<int> s;
        for (int x : candyType)
        {
            s.insert(x);
        }

        int distCandies = s.size(), n = candyType.size() / 2;
        return min(distCandies, n);
    }
};