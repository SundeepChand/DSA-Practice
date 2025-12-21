#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int largestInteger(int num)
    {
        multiset<int> odd, even;
        int temp = num;
        while (num)
        {
            int d = num % 10;
            if (d % 2 == 0)
                even.insert(d);
            else
                odd.insert(d);
            num /= 10;
        }

        int ans = 0;
        while (temp)
        {
            int d = temp % 10, cur;
            if (d % 2 == 0)
            {
                cur = (*even.begin());
                even.erase(even.begin());
            }
            else
            {
                cur = (*odd.begin());
                odd.erase(odd.begin());
            }
            ans = 10 * ans + cur;
            temp /= 10;
        }
        temp = ans, ans = 0;
        while (temp)
        {
            ans = 10 * ans + (temp % 10);
            temp /= 10;
        }
        return ans;
    }
};