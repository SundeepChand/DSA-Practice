#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

bool shouldSwap(char str[], int start, int curr)
{
    for (int i = start; i < curr; i++)
        if (str[i] == str[curr])
            return 0;
    return 1;
}

// Prints all distinct permutations in str[0..n-1]
void findPermutations(char str[], int index, int n)
{
    if (index >= n)
    {
        cout << str << endl;
        return;
    }

    for (int i = index; i < n; i++)
    {

        // Proceed further for str[i] only if it
        // doesn't match with any of the characters
        // after str[index]
        bool check = shouldSwap(str, index, i);
        if (check)
        {
            swap(str[index], str[i]);
            findPermutations(str, index + 1, n);
            swap(str[index], str[i]);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    char str[] = "ABCA";
    int n = strlen(str);
    findPermutations(str, 0, n);
    return 0;
}