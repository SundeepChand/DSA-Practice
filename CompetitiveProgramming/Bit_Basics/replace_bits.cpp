#include <bits/stdc++.h>
using namespace std;

int replaceBits(int n, int m, int i, int j)
{
    m <<= i;
    int mask_m = (1 << (j + 1)) - 1;
    m = m & mask_m; // Clear all the bits beyond j in m

    int mask = (1 << i) - 1;     // 0000111
    int mask2 = (~0) << (j + 1); // 1100000
    mask |= mask2;               // 1100111
    return ((n & mask) | m);
}

int main()
{
    int n = 15, m = 2, i = 1, j = 3;

    cout << replaceBits(n, m, i, j) << endl;
    return 0;
}