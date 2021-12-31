#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;

class Solution
{
public:
    int findComplement(int num)
    {
        unsigned int mask = ~0;
        while (mask & num)
            mask <<= 1;
        return (~mask) ^ num;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    Solution s;
    cout << s.findComplement(n);
    return 0;
}