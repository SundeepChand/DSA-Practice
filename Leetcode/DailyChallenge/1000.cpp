#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &stones, int i, int j, int &k)
    {
        if (j - i + 1 == k)
        {
            int sum = 0;
            for (int x = i; x <= j; x++)
                sum += stones[x];
            return sum;
        }

        int ans = INT_MAX;
        for (int l = i + k - 1; l <= j; l++)
        {
            int s = l - k + 1, e = l;
            int cost = solve(stones, s, e, k);
            int a = s - 1, b = e + 1, ctr = 1;
            while (ctr < k && a >= i && b <= j)
            {
                if (a < i)
                    cost += stones[b], b++;
                else if (b > j)
                    cost += stones[a], a--;
                if (stones[a] < stones[b])
                    cost += stones[a], a--;
                else
                    cost += stones[b], b++;
                ctr++;
            }
            ans = min(ans, cost);
        }
        return ans;
    }

    int mergeStones(vector<int> &stones, int k)
    {
        int n = stones.size();
        if (k > 2 && (n % (k - 1)) != 1)
            return -1;

        return solve(stones, 0, n - 1, k);
    }
};