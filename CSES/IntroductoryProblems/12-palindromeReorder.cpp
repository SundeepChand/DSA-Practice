#include <bits/stdc++.h>
using namespace std;

/*
This solution is getting TLE
int main()
{
    string s;
    cin >> s;

    vector<int> freq(26, 0);
    for (char x : s)
        freq[x - 'A']++;

    string res = "";
    bool flag = true;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] == 0)
            continue;
        if (res != "" && freq[i] % 2 == 1)
        {
            flag = false;
            break;
        }
        else if (res == "" && freq[i] % 2 == 1)
        {
            for (int j = 0; j < freq[i]; j++)
                res += (i + 'A');
        }
    }
    for (int i = 0; flag && i < 26; i++)
    {
        if (freq[i] != 0 && freq[i] % 2 == 0)
        {
            for (int j = 0; j < freq[i]; j += 2)
            {
                res = char(i + 'A') + res;
                res = res + char(i + 'A');
            }
        }
    }
    if (flag)
        cout << res;
    else
        cout << "NO SOLUTION";
    cout << endl;
    return 0;
}
*/

int main()
{
    string s;
    cin >> s;

    int n = s.length();

    vector<int> freq(26, 0);
    for (char x : s)
        freq[x - 'A']++;

    int ctr = 0;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] % 2 == 1)
            ctr++;
    }
    if (ctr > 1)
    {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    char res[n + 1];
    res[n] = '\0';
    int start = 0, end = n - 1;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] % 2 == 0)
        {
            for (int j = 0; j < freq[i]; j += 2)
            {
                res[start] = res[end] = (i + 'A');
                start++;
                end--;
            }
        }
        else if (freq[i] % 2 == 1)
        {
            for (int j = 0; j < freq[i]; j++)
            {
                res[n / 2 - freq[i] / 2 + j] = (i + 'A');
            }
        }
    }
    cout << res << endl;

    return 0;
}