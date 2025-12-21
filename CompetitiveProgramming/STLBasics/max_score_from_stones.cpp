#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumScore(int a, int b, int c)
    {
        priority_queue<int> pq;
        pq.push(a), pq.push(b), pq.push(c);

        int ans = 0;
        while (pq.size() > 1)
        {
            int p = pq.top();
            pq.pop();
            int q = pq.top();
            pq.pop();
            p--, q--;
            ans++;
            if (p > 0)
                pq.push(p);
            if (q > 0)
                pq.push(q);
        }
        return ans;
    }
};