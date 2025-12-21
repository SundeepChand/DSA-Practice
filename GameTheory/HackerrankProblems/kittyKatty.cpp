// https://www.hackerrank.com/challenges/kitty-and-katty/problem
#include <bits/stdc++.h>
using namespace std;

/*

The key thing to note is that for any two integers A and B, if there are only three possibilities:
1) (A-B=0) modulo 3
2) (A-B=1) modulo 3 and (B-A=2) modulo 3
3) (B-A=1) modulo 3 and (A-B=2) modulo 3
Hence, whoever first gets to the two item state always has a winning move.

*/

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        if (n == 1)
            cout << "Kitty";
        else
        {
            if (n % 2)
                cout << "Katty";
            else
                cout << "Kitty";
        }
        cout << endl;
    }
    return 0;
}