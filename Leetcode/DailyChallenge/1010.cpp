#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        map<int, int> m;
        int n = time.size();

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int x = time[i] % 60;
            ans += m[(60 - x) % 60];
            m[x]++;
        }
        return ans;
    }
};