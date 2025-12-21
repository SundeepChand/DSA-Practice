#include <bits/stdc++.h>
using namespace std;
int c(int n)
{
    int ctr = 0;
    while (n)
    {
        ctr += (n & 1);
        n /= 2;
    }
    return ctr;
}

bool comparator(int a, int b)
{
    int ca = c(a), cb = c(b);
    if (ca == cb)
        return a < b;
    return ca < cb;
}

vector<int> cardinalitySort(vector<int> nums)
{
    sort(nums.begin(), nums.end(), comparator);
    return nums;
}

int main()
{
    vector<int> v = {1, 2, 3, 4};
    v = cardinalitySort(v);

    for (auto x: v)
    {
        cout<<x<<" ";
    }
    return 0;
}