#include<bits/stdc++.h>
using namespace std;

/*
ctr1 = Number of elements that can be picked both by Alice & Bob
ctr2 = Number of elements that can be picked by Bob only
ctr3 = Number of elements that can be picked by Alice only

1) When Bob starts picking elements:
            ctr3
        0 | 1 | 2 | 3 | 4 |
        ___________________
 c   0 | A | B | B | B | B |
 t   1 | A | A | B | B | B |
 r   2 | A | A | A | B | B |
 3   3 | A | A | A | A | B |


2) When Alice starts picking elements:
            ctr2
        0 | 1 | 2 | 3 | 4 |
        ___________________
 c   0 | B | B | B | B | B |
 t   1 | A | B | B | B | B |
 r   2 | A | A | B | B | B |
 3   3 | A | A | A | B | B |

When ctr1 is non-zero, since Bob goes first, he will always let Alice
start picking the elements from ctr2 & ctr3 because in that case, Bob
has more possibilities of winning.
*/
string solve(int n, int a, int b, vector<int> A)
{
    int ctr1 = 0, ctr2 = 0, ctr3 = 0;

    for (int i = 0; i < n; i++)
    {
        if (A[i] % a == 0 && A[i] % b == 0)
            ctr1++;
        else if (A[i] % a == 0)
            ctr2++;
        else if (A[i] % b == 0)
            ctr3++;
    }

    if (ctr1)
        ctr2++;

    if (ctr2 > ctr3)
        return "Bob";
    return "Alice";
}

int main()
{
    
    return 0;
}