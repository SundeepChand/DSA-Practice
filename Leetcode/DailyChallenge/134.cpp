#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();

        int total = 0, cur = 0, start = 0;
        for (int i = 0; i < n; i++)
        {
            int diff = gas[i] - cost[i];
            total += diff, cur += diff;
            if (cur < 0)
                start = i + 1, cur = 0;
        }
        if (total < 0)
            return -1;
        return start;
    }
};