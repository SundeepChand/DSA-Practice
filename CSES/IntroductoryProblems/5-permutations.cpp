#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 1)
        cout << 1;
    else if (n <= 3)
        cout << "NO SOLUTION";
    else
    {
        int s = (n + 2) / 2, c = s;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                cout << c << " ";
                c++;
            }
            else
                cout << (c - s) << " ";
        }
    }
    cout << endl;
    return 0;
}