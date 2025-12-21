// Applications of Bit Masking
#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n)
{
    int ans = 0;
    for (int i = 0; i < 31; i++)
        if (n & (1 << i))
            ans++;
    return ans;
}

int setKthBitToOne(int n, int k)
{
    return (n | (1 << k));
}

int setKthBitToZero(int n, int k)
{
    return (n & ~(1 << k));
}

int invertKthBit(int n, int k)
{
    return (n ^ (1 << k));
}

int setLastOneBitToZero(int n)
{
    return (n & (n - 1));
}

int getTheLastOneBit(int n)
{
    return (n & (-n));
}

int invertAllBitsBeforeLastOneBit(int n)
{
    return (n | (n - 1));
}

bool isPowerOfTwo(int n)
{
    return (n & (n - 1)) == 0;
}

int main()
{
    // 6 --> 000110
    cout << countSetBits(6) << endl;
    cout << countSetBits(INT_MAX) << endl;

    cout << setKthBitToOne(6, 0) << endl;
    cout << setKthBitToOne(6, 3) << endl;
    cout << setKthBitToZero(6, 2) << endl;
    cout << invertKthBit(6, 1) << endl;

    cout << setLastOneBitToZero(6) << endl;
    cout << getTheLastOneBit(6) << endl;
    cout << invertAllBitsBeforeLastOneBit(6) << endl;

    cout << isPowerOfTwo(8) << endl;
    cout << isPowerOfTwo(1 << 10) << endl;
    cout << isPowerOfTwo(6) << endl;

    // In-built functions for counting bits
    cout << __builtin_clz(6) << endl;      // Count leading 0's
    cout << __builtin_ctz(6) << endl;      // Count trailing 0's
    cout << __builtin_popcount(6) << endl; // Count number of 1's
    cout << __builtin_parity(6) << endl;   // Parity of the number of 1's

    return 0;
}