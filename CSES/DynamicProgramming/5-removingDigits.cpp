#include <bits/stdc++.h>
using namespace std;

int solveGreedy(int n)
{
    // In each step subtract the largest digit.
    if (n == 0)
        return 0;
    if (n < 10)
        return 1;

    int largest = 1;
    int temp = n;
    while (temp)
    {
        largest = max(largest, temp % 10);
        temp /= 10;
    }
    return 1 + solveGreedy(n - largest);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    cout << solveGreedy(n) << endl;
    return 0;
}