#include <bits/stdc++.h>
using namespace std;

class SolutionFromLeftSide
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        // Find the left most set bit, if it is 1 in both l & r,
        // then keep it else the AND will be zero
        int ans = 0;
        while (left & right)
        {
            // Find Left most set bit in both
            int x = left, y = right;
            long long int ls = 1, rs = 1;
            while (x)
            {
                ls <<= 1;
                x >>= 1;
            }
            while (y)
            {
                rs <<= 1;
                y >>= 1;
            }
            ls >>= 1;
            rs >>= 1;

            if (ls & rs)
            {
                ans |= ls;
                left = left & (~ls);
                right = right & (~rs);
            }
            else
                break;
        }
        return ans;
    }
};

class Solution
{
    // The problem reduces to finding the largest
    // common prefix in left & right from the left side
    // This is because, for ex:
    // left:  110011001010
    // right: 110010101000
    // The common prefix is 11001 => the ans is 110010000000
    // This is because while moving from left to right, ans must occur
    // in between which will set the ans to the above value.
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int ctr = 0;
        while (left != right)
        {
            left >>= 1;
            right >>= 1;
            ctr++;
        }
        left <<= ctr;
        return left;
    }
};