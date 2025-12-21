#include <bits/stdc++.h>
using namespace std;

int solve(int A, int B)
{
    while (__gcd(A, B) != 1)
        A /= __gcd(A, B);
    return A;
}