#include <bits/stdc++.h>
using namespace std;

void findSubsets(string s)
{
    int n = s.length();
    for (int i = 0; i < (1 << n); i++)
    {
        int num = i, j = 0;
        while (num)
        {
            if (num & 1)
            {
                cout << s[j];
            }
            num >>= 1;
            j++;
        }
        cout << endl;
    }
}

int main()
{
    string s = "abcd";
    findSubsets(s);
    return 0;
}